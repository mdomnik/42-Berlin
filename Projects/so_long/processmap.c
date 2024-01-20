/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:20:37 by mdomnik           #+#    #+#             */
/*   Updated: 2024/01/20 17:27:36 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_data(t_game *game, char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		free(line);
	close(fd);
	game->width = (ft_strlen(line)-1);
	game->height = get_map_height(game, map);
	game->score = get_collectable_count(game);
	free(line);
}

int	get_map_height(t_game *game, char *map)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		free(line);
	game->map = ft_strjoin_nl(game->map, line);
	free(line);
	height = 0;
	while (line)
	{
		height++;
		line = get_next_line(fd);
		if (line)
			game->map = ft_strjoin_nl(game->map, line);
	}
	close(fd);
	game->map_len = ft_strlen(game->map);
	free(line);
	return (height);
}

int	get_collectable_count(t_game *game)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (game->map[i])
	{
		if (game->map[i] == COLLEC_SYMB)
			count++;
		i++;
	}
	return (count);
}
