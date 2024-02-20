/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:18:42 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/20 00:58:01 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *a_stack)
{
	t_stack	*clone;

	clone = a_stack;
	while (clone->next != NULL)
	{
		if (clone->data <= clone->next->data)
			clone = clone->next;
		else
			return (0);
	}
	return (1);
}

int	ft_lstsize_ps(t_stack *lst)
{
	t_stack	*temp;
	int		i;

	temp = lst;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	datacmp(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->data > stack_b->data)
		return (1);
	else if (stack_a->data < stack_b->data)
		return (-1);
	else
		return (0);
}

t_stack	*get_head(t_stack *stack)
{
	t_stack	*head;

	head = stack;
	while (head->prev != NULL)
		head = head->prev;
	return (head);
}
