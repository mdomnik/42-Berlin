/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:30:25 by mdomnik           #+#    #+#             */
/*   Updated: 2023/09/07 20:29:18 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb);

int	ft_sqrt(int nb)
{
	long	a;
	long	num;

	num = nb;
	if (nb == 1)
		return (1);
	a = 0;
	while (a * a <= num)
	{
		if (nb == (a * a))
			return (a);
		a++;
	}
	return (0);
}

/*
#include <stdio.h>
int main (void)
{
	int	nb;
	nb = 13 * 13;
	printf("%d", ft_sqrt(nb));
}
*/
