/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:10:42 by mdomnik           #+#    #+#             */
/*   Updated: 2023/11/17 15:03:10 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;
	unsigned char	pc;
	size_t			i;

	ps = (unsigned char *) s;
	pc = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (ps[i] == pc)
			return ((void *) &ps[i]);
		i++;
	}
	return (NULL);
}
