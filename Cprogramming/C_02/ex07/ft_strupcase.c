/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:23:43 by mdomnik           #+#    #+#             */
/*   Updated: 2023/08/29 12:11:40 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strupcase(char *str);

char	*ft_strupcase(char *str)
{
	char	*str2;

	str2 = str;
	while (*str2 != '\0')
	{
		if (*str2 >= 97 && *str2 <= 122)
		{
			*str2 = *str2 - 32;
		}
		str2++;
	}
	return (str);
}

/*
int main (void)
{
	char *x;
	char test[50] = "as43218!(731a*%^!#&*%^Rdkljakljal";
	

	x = ft_strupcase(test);

	printf("%s", x);
}
*/
