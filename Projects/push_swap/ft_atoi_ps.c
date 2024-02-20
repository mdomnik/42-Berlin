/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 00:08:14 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/20 01:49:39 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_ps(const char *str)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace_ps(str[i]) == 1)
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		sign = sign * (-1);
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10;
		result = result + (str[i] - 48);
		i++;
	}
	result = result * sign;
	return (result);
}

int	ft_isspace_ps(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

t_stack	*find_lowest(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*low;

	temp = stack;
	low = stack;
	while (temp != NULL)
	{
		if (low->opnum < 0)
			low->opnum = low->opnum * (-1);
		if (temp->opnum < 0)
			temp->opnum = temp->opnum * (-1);
		if (temp->opnum < low->opnum)
			low = temp;
		temp = temp->next;
	}
	return (low);
}
