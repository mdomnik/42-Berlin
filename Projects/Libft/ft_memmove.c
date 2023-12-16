/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:26:40 by mdomnik           #+#    #+#             */
/*   Updated: 2023/11/16 17:20:15 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*pdest;
	char		*psrc;
	size_t		i;

	if (!dest && !src)
		return (NULL);
	pdest = (char *)dest;
	psrc = (char *)src;
	i = 0;
	if (pdest > psrc)
		while (n-- > 0)
			pdest[n] = psrc[n];
	else
	{
		while (i < n)
		{
			pdest[i] = psrc[i];
			i++;
		}
	}
	return (dest);
}
