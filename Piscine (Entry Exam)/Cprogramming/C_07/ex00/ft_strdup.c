/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:35:10 by mdomnik           #+#    #+#             */
/*   Updated: 2023/09/11 11:43:53 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*str;
	char	*ptr;
	int		l;

	l = 0;
	while (src[l] != '\0')
		l++;
	str = malloc(l + 1);
	ptr = str;
	while (*src)
		*ptr++ = *src++;
	*ptr = '\0';
	return (str);
}

/*
#include <unistd.h> 
int main (void)
{
	char *src = "Hello";

	char *srcdup = ft_strdup(src);

	while (*srcdup != '\0')
	{
		write(1, srcdup, 1);
		srcdup++;
	}
}
*/
