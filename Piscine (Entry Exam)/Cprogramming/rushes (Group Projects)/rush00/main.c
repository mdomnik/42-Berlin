/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:33:40 by mdomnik           #+#    #+#             */
/*   Updated: 2023/08/27 11:50:57 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush03(int x, int y);

int	main(void)
{
	int	a;
	int	b;

	a = 5;
	b = -1;
	if (a < 0 || b < 0)
	{
		a = 0;
		b = 0;
		rush03(a, b);
	}
	else
	{
		rush03(a, b);
	}
}
