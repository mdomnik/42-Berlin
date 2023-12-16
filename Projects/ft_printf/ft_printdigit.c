/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:07:25 by mdomnik           #+#    #+#             */
/*   Updated: 2023/11/25 21:26:28 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdigit(long n, int base, int booly)
{
	int		count;
	char	*symbols;

	if (booly == 1)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_printdigit(-n, base, booly) + 1);
	}
	else if (n < base)
	{
		return (ft_printchar(symbols[n]));
	}
	else
	{
		count = ft_printdigit((n / base), base, booly);
		return (count + ft_printdigit((n % base), base, booly));
	}
}
