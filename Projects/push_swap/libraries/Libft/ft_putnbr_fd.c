/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:53:53 by mdomnik           #+#    #+#             */
/*   Updated: 2023/11/19 18:05:38 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	longy;

	longy = n;
	if (longy < 0)
	{
		ft_putchar_fd('-', fd);
		longy *= -1;
	}
	if (longy > 9)
	{
		ft_putnbr_fd((longy / 10), fd);
		longy %= 10;
	}
	if (longy <= 9)
		ft_putchar_fd((longy + 48), fd);
}
