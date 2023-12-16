/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:21:19 by mdomnik           #+#    #+#             */
/*   Updated: 2023/08/27 16:08:17 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);
void	counter(char a, char b);
void	printer(char a, char b, char c, char d);
void	cdloop(char a, char b, char c, char d);

void	ft_print_comb2(void)
{
	char	a;
	char	b;

	b = '0';
	a = '0';
	while (!(a == '9' && b == '9'))
	{
		counter (a, b);
		if (b < '9')
		{
			b++;
		}
		else
		{
			a++;
			b = '0';
		}
	}
}

void	counter(char a, char b)
{
	char	c;
	char	d;

	if (b < '9')
	{
		c = a;
		d = b + 1;
	}
	else
	{
		c = a + 1;
		d = '0';
	}
	cdloop(a, b, c, d);
}

void	printer(char a, char b, char c, char d)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (!(a == '9' && b == '8' && c == '9' && d == '9'))
	{
		write(1, ", ", 2);
	}
}

void	cdloop(char a, char b, char c, char d)
{
	while (!(c == '9' && d == '9'))
	{
		if (d < '9')
		{
			printer(a, b, c, d);
			d++;
		}
		else
		{
			printer(a, b, c, d);
			c++;
			d = '0';
		}
	}
	printer(a, b, c, d);
}
