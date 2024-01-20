/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitandfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:32:58 by mdomnik           #+#    #+#             */
/*   Updated: 2024/01/20 17:15:09 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_connection(t_game *game)
{
	free_all(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	free_all(t_game *game)
{
	if (game->sprite.ground_tile != NULL)
		mlx_destroy_image(game->mlx_connection, game->sprite.ground_tile);
	if (game->sprite.wall != NULL)
		mlx_destroy_image(game->mlx_connection, game->sprite.wall);
	if (game->sprite.exit != NULL)
		mlx_destroy_image(game->mlx_connection, game->sprite.exit);
	if (game->sprite.collectable != NULL)
		mlx_destroy_image(game->mlx_connection, game->sprite.collectable);
	if (game->sprite.player != NULL)
		mlx_destroy_image(game->mlx_connection, game->sprite.player);
	if (game->sprite.score_bg != NULL)
		mlx_destroy_image(game->mlx_connection, game->sprite.score_bg);
	mlx_destroy_window(game->mlx_connection, game->mlx_win);
	mlx_destroy_display(game->mlx_connection);
	free(game->map);
	free(game->tempmap);
	free(game->step_str);
	free(game->mlx_connection);
	free(game);
}
