/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:58:24 by mdomnik           #+#    #+#             */
/*   Updated: 2023/09/06 13:10:10 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power);

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		return (nb * ft_recursive_power(nb, power - 1));
	}
}

/*
#include <stdio.h>
int main (void)
{
	int	nb;
	int	power;

	nb = 0;
	power = 0;
	printf("%d", ft_recursive_power(nb, power));

}
*/
