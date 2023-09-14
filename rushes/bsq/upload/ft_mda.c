/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:36:37 by mdomnik           #+#    #+#             */
/*   Updated: 2023/09/13 23:36:44 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char	**allocate_mda(int colums, int rows)
{
	int		i;
	char	**mtrx;

	i = 0;
	mtrx = malloc(colums * sizeof(char *));
	if (!mtrx)
		return (NULL);
	while (i < colums)
	{
		mtrx[i] = malloc (rows * sizeof(char));
		i++;
	}
	return (mtrx);
}

void	free_mda(char **mtrx, int colums)
{
	int	i;

	i = 0;
	while (i < colums)
	{
		free (mtrx[i]);
		i++;
	}
	free (mtrx);
}

void	print_mda(char **mtrx, int colums, int rows)
{
	int	c;
	int	r;

	c = 0;
	r = 0;
	while (c < colums)
	{
		while (r < rows)
		{
			write(1, &mtrx[c][r], 1);
			r++;
		}
		if (r == rows)
		{
			c++;
			r = 0;
			write(1, "\n", 1);
		}
	}
}
