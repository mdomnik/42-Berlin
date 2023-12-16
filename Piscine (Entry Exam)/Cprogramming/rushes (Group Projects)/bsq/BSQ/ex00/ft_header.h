/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarzt <jarzt@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:35:36 by jarzt             #+#    #+#             */
/*   Updated: 2023/09/12 10:35:36 by jarzt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	**allocate_mda(int rows, int colums);
void	free_mda(char **mtrx, int rows);
void print_mda(char **mtrx, int colums, int rows);
int		open_file(char *path);
void	save_map(char **mtrx, char *path);
int mtrx_init(char **mtrx, int i, int xstart, int ystart);
int	strlengthx(char **nb);
void check (char **mtrx, int xlgth, int ylgth);

#endif