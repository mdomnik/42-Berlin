/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:53:29 by mdomnik           #+#    #+#             */
/*   Updated: 2023/11/16 16:34:15 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	pc;

	i = 0;
	pc = (char)c;
	while (s[i])
	{
		if (s[i] == pc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == pc)
		return ((char *) &s[i]);
	return (NULL);
}
