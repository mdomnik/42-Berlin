/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:32:08 by mdomnik           #+#    #+#             */
/*   Updated: 2023/11/19 17:23:29 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ps;
	int		i;

	ps = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ps)
		return (NULL);
	i = 0; 
	while (s[i])
	{
		ps[i] = f(i, s[i]);
		i++;
	}
	ps[i] = '\0';
	return (ps);
}
