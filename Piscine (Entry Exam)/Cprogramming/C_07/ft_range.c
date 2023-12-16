/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:44:30 by mdomnik           #+#    #+#             */
/*   Updated: 2023/09/11 12:30:36 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*array;
	int	j;

	i = max - min;
	j = 0;
	array = (int *)malloc(i * sizeof(int));
	while (min < max)
	{
		array[j] = min;
		min++;
		j++;
	}
	return (array);
}

/*
#include <stdio.h>
int main (void)
{	
	int	*array;
	int	i;
	int	min = 4;
	int	max = 2000;
	
	i = 0;
	array = ft_range(min, max);
	while (array[i] != '\0')
	{
		printf(" %i", array[i]);
		i++;
	}
}
*/
