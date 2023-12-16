/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:32:11 by mdomnik           #+#    #+#             */
/*   Updated: 2023/09/06 12:05:35 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_factorial(int nb);

int	ft_iterative_factorial(int nb)
{
	int	a;

	a = (nb - 1);
	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	else
	{
		while (a > 0)
		{
			nb = nb * a;
			a--;
		}
		return (nb);
	}
}

/*
int main (void)
{
	int nb = 10;

	printf("%d", ft_iterative_factorial(nb));
}
*/
