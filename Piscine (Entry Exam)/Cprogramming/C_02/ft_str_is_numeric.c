/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:53:40 by mdomnik           #+#    #+#             */
/*   Updated: 2023/08/30 15:16:05 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str);

int	ft_str_is_numeric(char *str)
{
	int	a;

	a = 1;
	while (*str != '\0')
	{
		if (*str < 48 || *str > 57)
		{
			a--;
		}
		str++;
	}
	if (a <= 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

/*
int	main (void)
{
	int x;
	x = ft_str_is_numeric("021576217638");
	printf("%d", x);
}
*/
