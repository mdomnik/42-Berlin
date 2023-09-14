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

char	**allocate_mda(int colums, int rows)
{
	int	i;
	char **mtrx;

	i = 0;
	mtrx = malloc(colums * sizeof(char*) + 1);
	while (i < colums)
	{
		mtrx[i] = malloc(rows * sizeof(char));
		i++;
	}
	mtrx[i] = NULL;
	return (mtrx);
}

void	free_mda(char **mtrx, int colums)
{
	int	i;

	i = 0;
	while (i < colums)
	{
		free(mtrx[i]);
		i++;
	}
	free(mtrx);
}

void print_mda(char **mtrx, int colums, int rows)
{
	int	c;
	int	r;

	c = 0;
	r = 0;
	while(c < colums)
	{
		while(r < rows)
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

int	strlength(char **nb)
{
	int	i;

	i = 0;
	while (nb[0][i] != '\0')
	{
		i++;
	}
	return(i - 1);
}

int lengthy(char **mtrx)
{
	int		i;

	i = 0;
	while (mtrx[i] != NULL)
	{
		i++;
	}
	return(i);
}

int mtrx_init(char **mtrx, int i, int xstart, int ystart)
{
	int   x;
	int	  y;
	int   j;
	int	  k;

	j = strlength(mtrx);
	k = lengthy(mtrx);
	while (i < j)
	{
		y = 0;
		while (y < i && (ystart + y) <= k)
		{	
			x = 0;	
			while (x < i)
			{
				if	(mtrx[ystart + y][xstart + x] == 'o' || mtrx[ystart + y][xstart + x] == '\n')
						return(i - 1);
				x++;
			}
			y++;
		}
		if ((ystart + y) == k)
			return(i);
		i++;
	}
	return (i - 1);
}

void fill(char **mtrx, int i, int xstart, int ystart)
{
	int   j;
	int	  k;
	int   b;

	j = 0;
	b = xstart;
	while (j < i)
	{	
		k = 0;
		xstart = b;
		while (k < i)
		{	
				mtrx[ystart][xstart] = 'x';
				xstart++;
				k++;
			
		}
		ystart++;
		j++;
	}
}



void check(char **mtrx, int xlgth, int ylgth)
{
    int 	i;
	int     xstart;
	int     ystart;
	int		bgx;
	int		bgy;

	xstart = 0;
	ystart = 0;
	bgx = 0;
	bgy = 0;
	(void)xlgth;
	(void)ylgth;
	i = mtrx_init(mtrx, 0, xstart, ystart);
	printf("\n i: %d", i);
	printf("\n xlgth: %d\n", xlgth);
	printf("\n ylgnth: %d\n", ylgth);
	while (xstart < xlgth)
	{
		ystart = 0;
		while (ystart < ylgth)
		{
			if (mtrx_init(mtrx, 0, xstart, ystart) > i)
			{
				i = mtrx_init(mtrx, 0, xstart, ystart);
				bgx = xstart;
				bgy = ystart;
			}
				ystart++;
		}
		xstart++;
	}
	printf("biggest current: (%d,%d), biggest (%d,%d), i: %d\n", xstart, ystart, bgx, bgy, i);
	fill(mtrx, i, bgx, bgy);
	printf("\n %d", i);
}



