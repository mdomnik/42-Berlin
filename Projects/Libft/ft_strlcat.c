/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:11:01 by mdomnik           #+#    #+#             */
/*   Updated: 2023/11/16 15:49:40 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	c;

	a = 0;
	b = 0;
	c = 0;
	while (dst[a] != '\0')
		a++;
	while (src[b] != '\0')
		b++;
	if (size <= a)
		b = b + size;
	else
		b = b + a;
	while ((src[c] != '\0') && (a + 1) < size)
	{
		dst[a] = src[c];
		a++;
		c++;
	}
	dst[a] = '\0';
	return (b);
}
