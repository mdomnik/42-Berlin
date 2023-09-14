/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:52:13 by mdomnik           #+#    #+#             */
/*   Updated: 2023/09/14 17:34:15 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	strlength(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	j = 0;
	while (sep[j] != '\0')
		j++;
	k = j * (size -1);
	while (size > 0)
	{
		i = 0;
		size--;
		while (strs[size][i] != '\0')
		{
			i++;
		}
		k += i;
	}
	return (k);
}

void	transfer(char *toreturn, char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	k;
	int	boool;

	i = 0;
	j = 1;
	k = 0;
	boool = 0;
	while (toreturn[i] != '\0' && j < size)
	{
		while (strs[j][k] != '\0')
		{
			toreturn[i] = strs[j][k];
			i++;
			k++;
		}
		j++;
		k = 0;
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*toreturn;
	int		i;

	if (size == 0)
	{
		toreturn = (char *)malloc(0);
		return (toreturn);
	}
	i = strlength(size, strs, sep);
	toreturn = (char *)malloc((i * sizeof(char)) + 1);
	transfer(toreturn, strs, sep, size);
	return (toreturn);
}
/*
int main (void)
{
	char	*str[] = {"hello1","world2", "monkey"};
	char	**strs = str;
	char	*sep = " . ";
	int size;
	size = 4;
	printf("%s", ft_strjoin(size, strs, sep));
}
*/
