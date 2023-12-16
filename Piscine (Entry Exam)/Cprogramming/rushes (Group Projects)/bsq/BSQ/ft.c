/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spascual <spascual@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:35:31 by jarzt             #+#    #+#             */
/*   Updated: 2023/09/12 12:03:26 by spascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

void	debug(void)
{
	printf("Test Message.\n");
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	dot_to_x(void)
{
	int	fd;
	char	c;

	fd = open("map.dict", O_RDONLY);
	if (fd == -1) // checks if we opened the file succesfully
	{
		write(1, "404\n", 4);
		exit(1);
	}
	while (read(fd, &c, 1)) // while file is not over
	{
		if (c == '.')
		{
			c = 'x';
		}
		ft_putchar(c);
	}
	close(fd);
	write(1, "\n", 1);
}