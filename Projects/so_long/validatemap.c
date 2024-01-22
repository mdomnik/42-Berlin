/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validatemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:50:35 by mdomnik           #+#    #+#             */
/*   Updated: 2024/01/22 11:17:37 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_game *game, char *map)
{
	check_mins(game);
	check_rect(game, map);
	check_legalchar(game);
	check_haswalls(game);
	game->tempmap = ft_strdup(game->map);
	flood_fill(game, 0);
	error_flood(game);
}

void	check_mins(t_game *game)
{
	int	i;
	int	collectable;
	int	exit;
	int	start;

	i = 0;
	collectable = 0;
	exit = 0;
	start = 0;
	while (game->map[i])
	{
		if (game->map[i] == COLLEC_SYMB)
			collectable++;
		else if (game->map[i] == EXIT_SYMB)
			exit++;
		else if (game->map[i] == PLAYER_SYMB)
			start++;
		i++;
	}
	if (exit > 1 || start > 1)
		ft_printf(ERR_HIGHCOUNT);
	if (start < 1 || exit < 1 || collectable < 1)
		ft_printf(ERR_LESSPOI);
	if (start != 1 || exit != 1 || collectable < 1)
		close_connection(game);
}

void	check_rect(t_game *game, char *map)
{
	int		width;
	int		temp;
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	width = ft_strlen_nl(line);
	free (line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		temp = ft_strlen_nl(line);
		free(line);
		if (temp == -1)
			break ;
		if (temp != width || temp == -2)
		{
			ft_printf(ERR_NOTRECT);
			close_connection(game);
		}
	}
	free(line);
	close(fd);
}

void	check_legalchar(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i] != '1' && game->map[i] != '0' 
			&& game->map[i] != 'C' && game->map[i] != 'E' 
			&& game->map[i] != 'P')
		{
			ft_printf(ERR_INVCHAR);
			close_connection(game);
		}
		i++;
	}
}
