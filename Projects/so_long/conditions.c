/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:14:28 by mdomnik           #+#    #+#             */
/*   Updated: 2024/01/20 18:18:34 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_score(t_game *game)
{
	game->score -= 1;
	if (game->score_str == NULL)
		game->score_str = ft_itoa(game->score);
	if (!game->score_str)
		error_malloc(game);
}

void	display_score_step(t_game *game)
{
	game->score_str = ft_itoa(game->score);
	mlx_put_image_to_window
	(game->mlx_connection, game->mlx_win, game->sprite.score_bg, 5, 5);
	mlx_string_put
	(game->mlx_connection, game->mlx_win, 15, 22, 0xFFecaca4, "COINS}");
	mlx_string_put
	(game->mlx_connection, game->mlx_win, 55, 22, 0xFFecaca4, game->score_str);
	mlx_string_put
	(game->mlx_connection, game->mlx_win, 15, 35, 0xFFecaca4, "STEPS}");
	mlx_string_put
	(game->mlx_connection, game->mlx_win, 55, 35, 0xFFecaca4, game->step_str);
	free(game->score_str);
}

void	update_step(t_game *game)
{
	game->steps += 1;
	if (game->step_str)
		free(game->step_str);
	game->step_str = ft_itoa(game->steps);
	if (!game->score_str)
		error_malloc(game);
	ft_printf("steps: %d\n", game->steps);
}
