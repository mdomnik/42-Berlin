/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:03:25 by mdomnik           #+#    #+#             */
/*   Updated: 2023/08/29 11:11:20 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_uppercase(char *str);

int	ft_str_is_uppercase(char *str)
{
	int	a;

	a = 1;
	while (*str != '\0')
	{
		if (*str < 65 || *str > 90)
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
int main (void)
{
	int x;

	x = ft_str_is_uppercase("AiaSDASGAWRQ");

	printf("%d", x);

}
*/
