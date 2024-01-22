/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritehandle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:08:02 by mdomnik           #+#    #+#             */
/*   Updated: 2024/01/20 19:43:27 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sprites	init_sprites(void *mlx, t_game *game)
{
	t_sprites	sprite;
	int			img_width;
	int			img_height;

	sprite.ground_tile = mlx_xpm_file_to_image
		(mlx, "textures/tile.xpm", &img_width, &img_height);
	sprite.wall = mlx_xpm_file_to_image
		(mlx, "textures/wall.xpm", &img_width, &img_height);
	sprite.exit = mlx_xpm_file_to_image
		(mlx, "textures/exit.xpm", &img_width, &img_height);
	sprite.collectable = mlx_xpm_file_to_image
		(mlx, "textures/collectable.xpm", &img_width, &img_height);
	sprite.player = mlx_xpm_file_to_image
		(mlx, "textures/player.xpm", &img_width, &img_height);
	sprite.score_bg = mlx_xpm_file_to_image
		(mlx, "textures/score_bg.xpm", &img_width, &img_height);
	if (!sprite.ground_tile || !sprite.wall || !sprite.exit 
		|| !sprite.collectable || !sprite.player || !sprite.score_bg)
		error_image(game);
	return (sprite);
}

void	put_sprites(t_game *game)
{
	int	width;
	int	height;

	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			sprites_line(game, width, height);
			width++;
		}
		height++;
	}
}

void	sprites_line(t_game *game, int width, int height)
{
	display_score_step(game);
	if (game->map[height * game->width + width] == WALL_SYMB)
		mlx_put_image_to_window(game->mlx_connection, game->mlx_win, 
			game->sprite.wall, width * 64, height * 64);
	else if (game->map[height * game->width + width] == PLAYER_SYMB)
		mlx_put_image_to_window(game->mlx_connection, game->mlx_win,
			game->sprite.player, width * 64, height * 64);
	else if (game->map[height * game->width + width] == EXIT_SYMB)
		mlx_put_image_to_window(game->mlx_connection, game->mlx_win,
			game->sprite.exit, width * 64, height * 64);
	else if (game->map[height * game->width + width] == COLLEC_SYMB)
		mlx_put_image_to_window(game->mlx_connection, game->mlx_win,
			game->sprite.collectable, width * 64, height * 64);
	else
		mlx_put_image_to_window(game->mlx_connection, game->mlx_win,
			game->sprite.ground_tile, width * 64, height * 64);
}
