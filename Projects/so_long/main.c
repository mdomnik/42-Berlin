/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:36:41 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/03 19:33:56 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		exit (EXIT_FAILURE);
	}
	else
	{
		game = ft_calloc(12, sizeof(t_game));
		if (!game)
			error_malloc(game);
		check_format(game, argv[1]);
		init_game(game, argv[1]);
		mlx_hook(game->mlx_win, KEY_PRESS, 1L << 0, &input_manager, game);
		mlx_hook(game->mlx_win, CLOSE_ICON, 0, &close_connection, game);
		mlx_loop(game->mlx_connection);
		return (EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}

void	init_game(t_game *game, char *map)
{
	game->mlx_connection = mlx_init();
	get_map_data(game, map);
	check_map(game, map);
	game->sprite = init_sprites(game->mlx_connection, game);
	game->step_str = ft_itoa(0);
	game->mlx_win = mlx_new_window 
		(game->mlx_connection, game->width * 64,
			game->height * 64, "Space Escape");
	put_sprites(game);
	ft_printf("steps: %d\n", game->steps);
	display_score_step(game);
}
