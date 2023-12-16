/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarzt <jarzt@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:35:31 by jarzt             #+#    #+#             */
/*   Updated: 2023/09/12 10:35:31 by jarzt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

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

	lines = 0;
	colums = 0;
	fd = open_file(path);
	while (read(fd, &c, sizeof(c)))
	{
		mtrx[lines][colums] = c;
		colums++;
		if (c == '\n')
		{
			lines++;
			colums = 0;
		}
	}
	close(fd);
}