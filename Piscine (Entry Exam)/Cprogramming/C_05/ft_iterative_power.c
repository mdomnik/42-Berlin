/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:21:26 by mdomnik           #+#    #+#             */
/*   Updated: 2023/09/06 12:55:57 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power);

int	ft_iterative_power(int nb, int power)
{
	int	tempnb;

	tempnb = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		while (power > 1)
		{
			nb *= tempnb;
			power--;
		}
		return (nb);
	}
}

/*
#include <stdio.h>
int main (void)
{
	int	nb;
	int	power;

	nb = 3;
	power = 3;
	printf("%d", ft_iterative_power(nb, power));

}
*/
