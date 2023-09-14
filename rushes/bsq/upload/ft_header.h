/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:36:12 by mdomnik           #+#    #+#             */
/*   Updated: 2023/09/13 23:36:16 by mdomnik          ###   ########.fr       */
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
int		get_max_lines(char *path);
int		get_max_columns(char *path);
void	print_mda(char **mtrx, int colums, int rows);
int		open_file(char *path);
void	save_map(char **mtrx, char *path);
void	check(char **mtrx, int max_lines, int max_columns, int x_start);
int		row_len(char **mtrx);
int		column_len(char **nb);

#endif
