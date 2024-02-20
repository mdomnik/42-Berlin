/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeErr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:25:40 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/20 00:59:19 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

void	errorescape(t_stack *stack)
{
	ft_free(&stack);
	ft_printf("Error\n");
	exit(1);
}

void	freetemp(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

int	errors(char *num)
{
	if (!(*num == '-' || (*num >= '0' && *num <= '9')))
		return (1);
	if (*num == '-' && !(num[1] >= '0' && num[1] <= '9'))
		return (1);
	num++;
	while (*num)
	{
		if (!(*num >= '0' && *num <= '9'))
			return (1);
		num++;
	}
	return (0);
}

int	error_dup(t_stack *stack, long i)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->data == i)
			return (1);
		stack = stack->next;
	}
	return (0);
}
