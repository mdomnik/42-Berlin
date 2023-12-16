/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:07:13 by mdomnik           #+#    #+#             */
/*   Updated: 2023/11/16 16:37:38 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		count;
	int		fpos;
	char	pc;

	count = 0;
	fpos = -1;
	pc = (char)c;
	while (s[count])
		count++;
	while (count > -1)
	{
		if (s[count] == pc)
			return ((char *)&s[count]);
		count--;
	}
	if (s[count] == pc)
		return ((char *)&s[count]);
	return (NULL);
}
