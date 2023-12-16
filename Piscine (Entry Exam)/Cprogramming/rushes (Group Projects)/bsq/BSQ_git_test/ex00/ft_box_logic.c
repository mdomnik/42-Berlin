/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_box_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:35:45 by mdomnik           #+#    #+#             */
/*   Updated: 2023/09/13 23:35:47 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	row_len(char **mtrx);
int	column_len(char **nb);
// int	column_len(char **nb)
// {
// 	int	i;

// 	i = 0;
// 	while (nb[0][i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i - 1);
// }

// int	row_len(char **mtrx)
// {
// 	int	i;

// 	i = 0;
// 	while (mtrx[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

int	check_box(char **mtrx, int iterator, int xstart, int ystart)
{
	int	x;
	int	y;

	y = 0;
	while (y < iterator)
	{
		x = 0;
		while (x < iterator)
		{
			if (mtrx[ystart + y][xstart + x] == 'o' ||
				mtrx[ystart + y][xstart + x] == '\n')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	calculate_box_size(char **mtrx, int iterator, int xstart, int ystart)
{
	int	max_columns;
	int	max_rows;

	max_columns = column_len(mtrx);
	max_rows = row_len(mtrx);
	while (iterator < max_columns)
	{
		if (check_box(mtrx, iterator, xstart, ystart) == 0)
			return (iterator - 1);
		if ((ystart + iterator) == max_rows)
			return (iterator);
		iterator++;
	}
	return (iterator - 1);
}

void	fill(char **mtrx, int box_size, int x_start, int y_start)
{
	int	iterator_column;
	int	iterator_row;
	int	x_start_temp;

	iterator_column = 0;
	x_start_temp = x_start;
	while (iterator_column < box_size)
	{
		iterator_row = 0;
		x_start = x_start_temp;
		while (iterator_row < box_size)
		{
			mtrx[y_start][x_start] = 'x';
			x_start++;
			iterator_row++;
		}
		y_start++;
		iterator_column++;
	}
}

void	check(char **mtrx, int max_lines, int max_columns, int x_start)
{
	int	max_box_size;
	int	y_start;
	int	next_x;
	int	next_y;

	next_y = 0;
	max_box_size = 0;
	while (x_start < max_columns)
	{
		y_start = 0;
		while (y_start < max_lines)
		{
			if (calculate_box_size(mtrx, 0, x_start, y_start) > max_box_size)
			{
				max_box_size = calculate_box_size(mtrx, 0, x_start, y_start);
				next_x = x_start;
				next_y = y_start;
			}
			y_start++;
		}
		x_start++;
	}
	fill(mtrx, max_box_size, next_x, next_y);
}
