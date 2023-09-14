
/*
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

void check(void)
{
    int 	i;
	int     xstart;
	int     ystart;

	xstart = 0;
	ystart = 1;
	i = 0;

	i = mtrx_init(map, i, xstart, ystart);
	printf("\n %d", i);
}

int	strlength(char *nb)
{
	int	i;

	i = 0;
	while (nb[i] != '\n')
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

	j = strlength(*mtrx);
	while (i < j)
	{
		y = 0;
		while (y < i)
		{	
			x = 0;	
			while (x < i)
			{
				if	(mtrx[ystart + y][xstart + x] == 'o')
					return(i - 1);
				x++;
			}
			y++;
		}
		i++;
	}
	return (i - 1);
}
*/