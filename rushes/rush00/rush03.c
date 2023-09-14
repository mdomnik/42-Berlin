/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:51:42 by mdomnik           #+#    #+#             */
/*   Updated: 2023/08/26 15:03:07 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);
void	edgerows(int tempx, int x);
void	normrows(int tempx, int x);

void	rush03(int x, int y)
{
	int		firstrow;
	int		tempx;
	char	nl;

	nl = '\n';
	firstrow = y;
	tempx = x;
	while (y > 0)
	{
		if (y == firstrow || y == 1)
		{
			edgerows(tempx, x);
			ft_putchar(nl);
			tempx = x;
		}
		else
		{
			normrows(tempx, x);
			ft_putchar(nl);
			tempx = x;
		}
		y--;
	}
}

void	edgerows(int tempx, int x)
{
	char	b;
	char	a;
	char	c;
	char	nl;

	a = 'A';
	b = 'B';
	c = 'C';
	nl = '\n';
	while (tempx >= 1)
	{
		if (tempx == x)
		{
			ft_putchar(a);
		}
		else if (tempx == 1)
		{
			ft_putchar(c);
		}
		else
		{
			ft_putchar(b);
		}
		tempx--;
	}
}

void	normrows(int tempx, int x)
{
	char	b;
	char	space; 
	char	nl; 

	b = 'B';
	space = ' ';
	nl = '\n';
	while (tempx >= 1)
	{
		if (tempx == x || tempx == 1)
		{
			ft_putchar(b);
		}
		else
		{
			ft_putchar(space);
		}
		tempx--;
	}
}
