/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:14:09 by mdomnik           #+#    #+#             */
/*   Updated: 2023/08/29 12:19:46 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strlowcase(char *str);

char	*ft_strlowcase(char *str)
{
	char	*str2;

	str2 = str;
	while (*str2 != '\0')
	{
		if (*str2 >= 65 && *str2 <= 90)
		{
			*str2 = *str2 + 32;
		}
		str2++;
	}
	return (str);
}
/*
int	main (void)
{
	char	*x;
	char	test[50] = "fshdaQWFUGWQUIFG1243!";
	

	x = ft_strlowcase(test);

	printf("%s", x);
}
*/
