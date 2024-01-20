/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:00:02 by mdomnik           #+#    #+#             */
/*   Updated: 2024/01/20 17:31:24 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_wall(t_game *game)
{
	ft_printf(ERR_WALL);
	close_connection(game);
}

void	error_flood(t_game *game)
{
	int	i;
	int	score;
	int	checks;

	i = 0;
	score = game->score;
	checks = 2 + score;
	while (i <= game->map_len)
	{
		checks = error_flood_p2(game, checks, i);
		i++;
	}
	if (checks > 0)
	{
		ft_printf(ERR_FLOOD);
		close_connection(game);
	}
}

int	error_flood_p2(t_game *game, int checks, int i)
{
	if (game->tempmap[i] == 'P' || game->tempmap[i] == 'C'
		|| game->tempmap[i] == 'E' || game->tempmap[i] == 'c')
		if (game->tempmap[i + 1] == '2' || game->tempmap[i - 1] == '2' 
			|| game->tempmap[i + game->width] == '2'
			|| game->tempmap[i - game->width] == '2' 
			|| game->tempmap[i + 1] == 'C' || game->tempmap[i - 1] == 'C'
			|| game->tempmap[i + game->width] == 'C' 
			|| game->tempmap[i - game->width] == 'C' 
			|| game->tempmap[i + 1] == 'c' || game->tempmap[i - 1] == 'c'
			|| game->tempmap[i + game->width] == 'c' 
			|| game->tempmap[i - game->width] == 'c')
			checks--;
	return (checks);
}

void	error_malloc(t_game *game)
{
	ft_printf(ERR_MALLOC);
	close_connection(game);
}

void	error_image(t_game *game)
{
	ft_printf(ERR_IMAGE);
	close_connection(game);
}
