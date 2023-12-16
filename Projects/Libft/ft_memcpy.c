/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:03:19 by mdomnik           #+#    #+#             */
/*   Updated: 2023/11/16 14:38:06 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*psrc;
	char		*pdest;
	size_t		i;

	psrc = src;
	pdest = dest;
	i = 0;
	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	while (i < n)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return (dest);
}
