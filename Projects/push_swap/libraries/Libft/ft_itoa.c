/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:01:16 by mdomnik           #+#    #+#             */
/*   Updated: 2023/11/20 15:14:38 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n);

char	*ft_itoa(int n)
{
	char		*ret;
	int			end;
	int			temp;
	long int	longy;

	longy = n;
	end = int_len(longy);
	ret = (char *)malloc((end + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[end] = '\0';
	if (longy < 0)
	{
		longy = (longy * (-1));
		ret[0] = '-';
	}
	while (longy > 9)
	{
		temp = longy % 10;
		longy = longy / 10;
		ret[end - 1] = (char)(temp + '0');
		end--;
	}
	ret[end - 1] = (char)(longy + '0');
	return (ret);
}

static int	int_len(int n)
{
	int	digits;

	digits = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = (n * (-1));
		digits++;
	}
	while (n > 9)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}
