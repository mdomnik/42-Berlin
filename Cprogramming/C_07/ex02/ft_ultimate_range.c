/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:33:54 by mdomnik           #+#    #+#             */
/*   Updated: 2023/09/11 13:30:33 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	j;

	i = max - min;
	j = 0;
	*range = (int *)malloc(i * sizeof(int));
	while (min < max)
	{
		(*range)[j] = min;
		min++;
		j++;
	}
	if (i < 0)
		return (-1);
	return (i);
}

/*
#include <stdio.h>
int main() 
{
    int *range;
    int min = 1;
    int max = 50000000;
    int size;
    size = ft_ultimate_range(&range, min, max);
    if (size == -1) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }
    printf("Generated Range: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", range[i]);
    }
    // Free the allocated memory
    free(range);
    return 0;
}
*/
