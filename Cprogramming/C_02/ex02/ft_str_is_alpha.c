/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:52:46 by mdomnik           #+#    #+#             */
/*   Updated: 2023/08/28 21:29:15 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h> 

int	ft_str_is_alpha(char *str);

int	ft_str_is_alpha(char *str)
{
	int	a;

	a = 1;
	while (*str != '\0')
	{
		if (*str < 65 || (*str > 90 && *str < 97) || *str > 122)
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
	x = ft_str_is_alpha("aAPHUIWDSVDSHILDWEbhvdwghkdgdgbjhgebjhrgjhq");
	printf("%d", x);
}
*/
