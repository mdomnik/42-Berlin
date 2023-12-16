/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarzt <jarzt@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:35:31 by jarzt             #+#    #+#             */
/*   Updated: 2023/09/12 10:35:31 by jarzt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

/*

COnditions for when full, empty or obstacle are the same

*/

bool	conditions(char empty, char obstacle, char full);

int	main(void)
{
	int	empty;
	int	obstacle;
	int	full;
	int	result;

	empty = '7';
	obstacle = '8';
	full = '7';
	result = conditions(empty, obstacle, full);
	printf("%d\n", result);
	printf("Full: %c\n", full);
	return (0);
}

bool	conditions(char empty, char obstacle, char full)
{
	if (empty == obstacle)
	{
		return (0);
	}
	while (empty == full || obstacle == full)
	{
		full++;
	}
	return (1);
}
