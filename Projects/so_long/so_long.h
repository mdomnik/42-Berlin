/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:06:08 by mdomnik           #+#    #+#             */
/*   Updated: 2024/01/20 19:23:00 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include "libraries/Libft/libft.h"
# include "libraries/mlx/mlx.h"
# include "libraries/ft_printf/ft_printf.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

//Error Messages
# define ERR_HIGHCOUNT	"Error\nMore than 1 start or exit\n"
# define ERR_LESSPOI	"Error\nMap must contain at least 1 P, E, and C\n"
# define ERR_NOTRECT	"Error\nMap must be a rectangle\n"
# define ERR_INVCHAR	"Error\nMap contains invalid characters\n"
# define ERR_WALL		"Error\nWalls must enclose the play area\n"
# define ERR_FLOOD		"Error\nNo valid path to all regions of the play area\n"
# define ERR_FORMAT		"Error\nInvalid map file format\n"
# define ERR_MALLOC		"Error\nMalloc failed to allocate memory\n"
# define ERR_IMAGE		"Error\nImage has failed to be initialted\n"

//enum defines characters found in .ber file
typedef enum e_map_symb {
	WALL_SYMB = '1',
	GROUND_SYMB = '0',
	EXIT_SYMB = 'E',
	COLLEC_SYMB = 'C',
	PLAYER_SYMB = 'P',
	FLOOD_SYMB = '2',
	PC_SYMB = 'c',
}	t_map_symb;

//enum defines values of keyboard inputs
typedef enum e_key_code {
	CLOSE_ICON = 17,
	ESC_KEY = 65307,
	KEY_PRESS = 2,
	KEY_RELEASE = 3,
	UP_ARROW_KEY = 65362,
	DOWN_ARROW_KEY = 65364,
	LEFT_ARROW_KEY = 65361,
	RIGHT_ARROW_KEY = 65363,
	W_KEY = 119,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100
}	t_key_code;

//variables storing initialized sprite images
typedef struct s_sprites {
	void	*ground_tile;
	void	*wall;
	void	*exit;
	void	*collectable;
	void	*player;
	void	*score_bg;
}					t_sprites;

//variables connected to the connection with X window system,
//map processes, and value tracking
typedef struct s_game {
	void		*mlx_connection;
	void		*mlx_win;
	t_sprites	sprite;
	int			width;
	int			height;
	int			map_len;
	char		*map;
	char		*tempmap;
	int			score;
	char		*score_str;
	int			steps;
	char		*step_str;
}					t_game;

//conditions.c
void			update_score(t_game *game);
void			display_score_step(t_game *game);
void			update_step(t_game *game);

//exitandfree.c
int				close_connection(t_game *game);
void			free_all(t_game *game);

//inputs.c
int				input_manager(int keycode, t_game *game);
void			move_up(t_game *game);
void			move_down(t_game *game);
void			move_right(t_game *game);
void			move_left(t_game *game);

//main.c
void			init_game(t_game *game, char *map);

//processmap.c
void			get_map_data(t_game *game, char *map);
int				get_map_height(t_game *game, char *map);
int				get_collectable_count(t_game *game);

//spritehandle.c
void			put_sprites(t_game *game);
void			sprites_line(t_game *game, int width, int height);
t_sprites		init_sprites(void *mlx, t_game *game);

//utils.c
char			*ft_strdup_nl(char *s1);
int				ft_strlcpy_nl(char *dst, const char *src, int size);
char			*ft_strjoin_nl(char *s1, char *s2);
int				ft_strlen_nl(const char *s);

//validatemap.c
void			check_map(t_game *game, char *map);
void			check_mins(t_game *game);
void			check_rect(t_game *game, char *map);
void			check_legalchar(t_game *game);

//validatemap2.c
void			check_haswalls(t_game *game);
void			flood_fill(t_game *game, int i);
void			check_format(t_game *game, char *map);

//errors.c
void			error_wall(t_game *game);
void			error_flood(t_game *game);
void			error_malloc(t_game *game);
void			error_image(t_game *game);
int				error_flood_p2(t_game *game, int checks, int i);

#endif