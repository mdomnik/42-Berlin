/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:09:34 by mdomnik           #+#    #+#             */
/*   Updated: 2023/09/10 17:02:15 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb);

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else if (nb > 0)
		return (nb * ft_recursive_factorial(nb - 1));
	else
		return (nb);
}

/*
#include <stdio.h>
int main (void)
{
	int	nb;

	nb = 15;
	printf("%d", ft_recursive_factorial(nb));
}
*/
