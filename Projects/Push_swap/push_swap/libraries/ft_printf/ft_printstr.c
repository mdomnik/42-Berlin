/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:58:47 by mdomnik           #+#    #+#             */
/*   Updated: 2023/11/25 21:03:51 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		ft_printstr("(null)");
		return (6);
	}
	while (*str)
	{
		ft_printchar((int)*str);
		++str;
		++count;
	}
	return (count);
}
