/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:59:34 by mdomnik           #+#    #+#             */
/*   Updated: 2023/08/30 15:18:44 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowercase(char *str);

int	ft_str_is_lowercase(char *str)
{
	int	a;

	a = 1;
	while (*str != '\0')
	{
		if (*str < 97 || *str > 122)
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
	x = ft_str_is_lowercase("dfasdgjahasYd");
	printf("%d", x);
}
*/
