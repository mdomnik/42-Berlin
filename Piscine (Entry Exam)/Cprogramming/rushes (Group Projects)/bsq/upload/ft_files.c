/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:36:01 by mdomnik           #+#    #+#             */
/*   Updated: 2023/09/13 23:36:06 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	column_len(char **nb)
{
	int	i;

	i = 0;
	while (nb[0][i] != '\0')
	{
		i++;
	}
	return (i - 1);
}

int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(1, "WRONG FILE PATH", 15);
		return (-1);
	}
	return (fd);
}

void	save_map(char **mtrx, char *path)
{
	int		fd;
	char	c;
	int		lines;
	int		colums;
	int		brr;

	lines = 0;
	colums = 0;
	brr = 0;
	fd = open_file(path);
	while (read(fd, &c, 1) > 0)
	{
		if (brr > 0)
			mtrx[lines][colums] = c;
		colums++;
		if (c == '\n')
		{
			if (brr > 0)
				lines++;
			colums = 0;
			brr++;
		}
	}
	close(fd);
}

int	get_max_lines(char *path)
{
	int		fd;
	char	c;
	int		lines;

	fd = open_file(path);
	lines = 0;
	while (read(fd, &c, sizeof(c)) > 0)
	{
		if (c == '\n')
		{
			lines++;
		}
	}
	close(fd);
	return (lines);
}

int	get_max_columns(char *path)
{
	int		fd;
	char	c;
	int		column;

	fd = open_file(path);
	column = 0;
	while (read(fd, &c, sizeof(c)) > 0)
	{
		column++;
		if (c == '\n')
		{
			column = 0;
		}
	}
	close(fd);
	return (column);
}
