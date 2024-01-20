/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:17:08 by mdomnik           #+#    #+#             */
/*   Updated: 2024/01/20 18:17:04 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	input_manager(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		close_connection(game);
	if (keycode == W_KEY || keycode == UP_ARROW_KEY)
		move_up(game);
	if (keycode == S_KEY || keycode == DOWN_ARROW_KEY)
		move_down(game);
	if (keycode == D_KEY || keycode == RIGHT_ARROW_KEY)
		move_right(game);
	if (keycode == A_KEY || keycode == LEFT_ARROW_KEY)
		move_left(game);
	return (EXIT_SUCCESS);
}

void	move_up(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != PLAYER_SYMB)
		i++;
	if (game->map[i - game->width] == COLLEC_SYMB)
		update_score(game);
	if (game->map[i - game->width] == EXIT_SYMB && game->score == 0)
	{
		update_step(game);
		game->map[i] = GROUND_SYMB;
		game->map[i - 1] = PLAYER_SYMB;
		close_connection(game);
	}
	if (game->map[i - game->width] != WALL_SYMB
		&& game->map[i - game->width] != EXIT_SYMB)
	{
		update_step(game);
		game->map[i] = GROUND_SYMB;
		game->map[i - game->width] = PLAYER_SYMB;
		put_sprites(game);
	}
}

void	move_down(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != PLAYER_SYMB)
		i++;
	if (game->map[i + game->width] == COLLEC_SYMB)
		update_score(game);
	if (game->map[i + game->width] == EXIT_SYMB && game->score == 0)
	{
		update_step(game);
		game->map[i] = GROUND_SYMB;
		game->map[i - 1] = PLAYER_SYMB;
		close_connection(game);
	}
	else if (game->map[i + game->width] != WALL_SYMB 
		&& game->map[i + game->width] != EXIT_SYMB)
	{
		update_step(game);
		game->map[i] = GROUND_SYMB;
		game->map[i + game->width] = PLAYER_SYMB;
		put_sprites(game);
	}
}

void	move_right(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != PLAYER_SYMB)
		i++;
	if (game->map[i + 1] == COLLEC_SYMB)
		update_score(game);
	if (game->map[i + 1] == EXIT_SYMB && game->score == 0)
	{
		update_step(game);
		game->map[i] = GROUND_SYMB;
		game->map[i - 1] = PLAYER_SYMB;
		close_connection(game);
	}
	else if (game->map[i + 1] != WALL_SYMB && game->map[i + 1] != EXIT_SYMB)
	{
		update_step(game);
		game->map[i] = GROUND_SYMB;
		game->map[i + 1] = PLAYER_SYMB;
		put_sprites(game);
	}
}

void	move_left(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != PLAYER_SYMB)
		i++;
	if (game->map[i - 1] == COLLEC_SYMB)
		update_score(game);
	if (game->map[i - 1] == EXIT_SYMB && game->score == 0)
	{
		update_step(game);
		game->map[i] = GROUND_SYMB;
		game->map[i - 1] = PLAYER_SYMB;
		close_connection(game);
	}
	else if (game->map[i - 1] != WALL_SYMB && game->map[i - 1] != EXIT_SYMB)
	{
		update_step(game);
		game->map[i] = GROUND_SYMB;
		game->map[i - 1] = PLAYER_SYMB;
		put_sprites(game);
	}
}
