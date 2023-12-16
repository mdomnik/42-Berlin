/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:27:36 by mdomnik           #+#    #+#             */
/*   Updated: 2023/12/04 14:58:04 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s);

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	while (i < count * size)
	{
		tmp[i++] = 0;
	}
	return (tmp);
}

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

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;

	dest = (char *) malloc(ft_strlen(s1) + 1);
	i = 0;
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}