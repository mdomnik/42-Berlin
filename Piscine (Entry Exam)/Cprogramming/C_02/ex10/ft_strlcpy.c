/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:25:09 by mdomnik           #+#    #+#             */
/*   Updated: 2023/09/02 11:27:05 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	a;

	a = 0;
	i = 0;
	while (src[i] != '\0')
	{
		i++;
		a++;
	}
	if (i < size)
	{
		i = 0;
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
	}
	while (i < size)
	{
		dest[i] = '\0';
		i++;
	}
	return (a);
}

/*
int	main(void)
{
	unsigned int n = 9;
	char src[] = "Hello";
	char dest[n];
	int	x;

	x = ft_strlcpy(dest, src, n);
	printf("%s", dest);
	printf("%d", x);
}
*/
