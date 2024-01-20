/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:45:07 by mdomnik           #+#    #+#             */
/*   Updated: 2024/01/20 17:46:09 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup_nl(char *s1)
{
	char	*dest;
	size_t	i;

	dest = (char *) malloc(ft_strlen(s1) + 1);
	i = 0;
	if (!dest)
		return (NULL);
	while (s1[i] && s1[i] != '\n')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	ft_strlcpy_nl(char *dst, const char *src, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (size <= 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (src[i] && i < (size - 1) && src[i] != '\n')
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	while (src[i])
	{
		i++;
	}
	dst[j] = '\0';
	return (i);
}

char	*ft_strjoin_nl(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*dst;

	dst = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup_nl(s2));
	else if (s2 == NULL)
		return (ft_strdup_nl(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!(dst))
		return (NULL);
	ft_strlcpy_nl(dst, s1, s1_len + 1);
	ft_strlcpy_nl((dst + s1_len), s2, s2_len + 1);
	free(s1);
	free(s2);
	return (dst);
}

int	ft_strlen_nl(const char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			j++;
		i++;
	}
	i -= j;
	return (i);
}
