/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:11:09 by mdomnik           #+#    #+#             */
/*   Updated: 2023/09/05 11:52:00 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	calcs(int nb);
void	ft_putnbr(int nb);

int main(void)
{
	ft_putnbr(1);
}


void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
	}
	else
	{
		calcs(nb);
	}
}

int	if_negative(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * (-1);
	}
	return (nb);
}

void	calcs(int nb)
{
	int		a;
	int		count;
	char	digit	[40];

	a = 0;
	count = 0;
	nb = if_negative(nb);
	while (nb > 0)
	{
		a = nb % 10;
		nb /= 10;
		digit[count] = '0' + a;
		count++;
	}
	count--;
	while (count >= 0)
	{
		a = digit[count];
		write(1, &a, 1);
		count--;
	}
}
