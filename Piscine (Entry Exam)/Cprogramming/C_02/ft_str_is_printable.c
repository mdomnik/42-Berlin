/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:12:14 by mdomnik           #+#    #+#             */
/*   Updated: 2023/08/30 15:23:03 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str);

int	ft_str_is_printable(char *str)
{
	int	a;

	a = 1;
	while (*str != '\0')
	{
		if (*str < 32 || *str > 126)
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
	int	x;

	x = ft_str_is_printable("mfiwo3!#^@&!^DEL\x08\xDE\xAD");

	printf("%d", x);
}
*/
