/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:33:38 by mdomnik           #+#    #+#             */
/*   Updated: 2023/11/16 17:02:19 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char			*ps1;
	const char			*ps2;
	size_t				i;

	ps1 = s1;
	ps2 = s2;
	i = 0;
	while (i < n)
	{
		if (ps1[i] == ps2[i])
			i++;
		else
			return ((unsigned char)ps1[i] - (unsigned char)ps2[i]); 
	}
	return (0);
}
