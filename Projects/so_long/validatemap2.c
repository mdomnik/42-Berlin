/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validatemap2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:42:46 by mdomnik           #+#    #+#             */
/*   Updated: 2024/01/20 17:56:22 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_haswalls(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	while (h < game->height)
	{
		w = 0;
		while (w < game->width)
		{
			if (h == 0 || h == game->height - 1)
			{
				if (game->map[(h * game->width) + w] != '1')
					error_wall(game);
			}
			else if (w == 0 || w == game->width - 1)
			{
				if (game->map[(h * game->width) + w] != '1')
					error_wall(game);
			}
			w++;
		}
		h++;
	}
}

void	flood_fill(t_game *game, int i)
{
	if (i == 0) 
		while (i < game->map_len && game->tempmap[i] != PLAYER_SYMB)
			i++;
	if (i < 0 || i >= game->map_len || game->tempmap[i] == EXIT_SYMB)
		return ;
	if (game->tempmap[i] != PLAYER_SYMB && game->tempmap[i] != COLLEC_SYMB 
		&& game->tempmap[i] != EXIT_SYMB && game->tempmap[i] != PC_SYMB)
		game->tempmap[i] = FLOOD_SYMB;
	if (game->tempmap[i] == COLLEC_SYMB || game->tempmap[i] == PLAYER_SYMB)
		game->tempmap[i] = PC_SYMB;
	if ((i + 1) < game->map_len && game->tempmap[i + 1] != WALL_SYMB && 
		game->tempmap[i + 1] != FLOOD_SYMB && game->tempmap[i + 1] != PC_SYMB)
		flood_fill(game, i + 1);
	if ((i - 1) >= 0 && game->tempmap[i - 1] != WALL_SYMB && 
		game->tempmap[i - 1] != FLOOD_SYMB && game->tempmap[i - 1] != PC_SYMB)
		flood_fill(game, i - 1);
	if ((i + game->width) < game->map_len && game->tempmap[i + game->width]
		!= WALL_SYMB && game->tempmap[i + game->width] != FLOOD_SYMB 
		&& game->tempmap[i + game->width] != PC_SYMB)
		flood_fill(game, i + game->width);
	if ((i - game->width) >= 0 && game->tempmap[i - game->width] != WALL_SYMB
		&& game->tempmap[i - game->width] != FLOOD_SYMB 
		&& game->tempmap[i + game->width] != PC_SYMB)
		flood_fill(game, i - game->width);
}

void	check_format(t_game *game, char *map)
{
	char	*output;
	int		i;

	i = game->width;
	output = ft_strnstr(map, ".ber", ft_strlen(map));
	if (output == 0)
	{
		ft_printf(ERR_FORMAT);
		close_connection(game);
	}
}
