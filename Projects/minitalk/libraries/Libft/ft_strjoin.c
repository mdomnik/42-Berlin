/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:39:39 by mdomnik           #+#    #+#             */
/*   Updated: 2023/11/17 15:48:26 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pstr;
	size_t	count1;
	size_t	count2;

	count1 = 0;
	count2 = 0;
	pstr = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!pstr)
		return (NULL);
	while (count1 < ft_strlen(s1))
	{
		pstr[count1] = s1[count1];
		count1++;
	}
	while (count2 < ft_strlen(s2))
	{
		pstr[count1 + count2] = s2[count2];
		count2++;
	}
	pstr[count1 + count2] = '\0';
	return (pstr);
}
