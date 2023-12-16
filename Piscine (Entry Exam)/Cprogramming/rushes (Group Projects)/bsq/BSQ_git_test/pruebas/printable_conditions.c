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

#include <stdbool.h>
#include <stdio.h>

/*

Check all efo is printable NOT WORKING!!!!!!!!!!!!!

*/

bool	ft_str_is_printable(char empty, char full, char obstacle);
bool	ft_isprint(char c);

int	main(void)
{
	char	empty;
	char	obstacle;
	char	full;
	int		result;

	empty = 'Ö';
	obstacle = '0';
	full = 'j';
	result = ft_str_is_printable(empty, obstacle, full);
	printf("%d\n", result);
	return (0);
}

bool	ft_str_is_printable(char empty, char full, char obstacle)
{
	return (ft_isprint(empty) && ft_isprint(full) && ft_isprint(obstacle));
}

bool	ft_isprint(char c)
{
	return (c >= 32 && c <= 126);
}
