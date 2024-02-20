/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:38:29 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/20 00:58:46 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*lowest;
	int		lstsize;

	lstsize = ft_lstsize_ps(*b_stack);
	lowest = low_num(b_stack);
	if ((lstsize / 2) > lowest->index)
	{
		while (lowest->next != NULL)
			rb(b_stack);
	}
	else
	{
		while (lowest->next != NULL)
			rrb(b_stack);
	}
	push_back(a_stack, b_stack);
}

t_stack	*low_num(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*lowstack;
	int		low;

	low = 2147483647;
	lowstack = *stack;
	temp = *stack;
	while (temp != NULL)
	{
		if (temp->data < low)
		{
			low = temp->data;
			lowstack = temp;
		}
		temp = temp->next;
	}
	return (lowstack);
}

void	push_back(t_stack **a_stack, t_stack **b_stack)
{
	while (ft_lstsize_ps(*b_stack) > 0)
	{
		pa(a_stack, b_stack);
	}
}

void	sort_low(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*temp;

	pop_cost_a(a_stack);
	while (ft_lstsize_ps(*a_stack) > 3 && (check_sort(*a_stack) != 1))
	{
		pop_cost_a(a_stack);
		temp = get_low_val(*a_stack);
		if (temp->cost < 0)
		{
			while ((*a_stack)->data != temp->data)
				rra(a_stack);
		}
		else
		{
			while ((*a_stack)->data != temp->data)
				ra(a_stack);
		}
		pb(a_stack, b_stack);
	}
	if (check_sort(*a_stack) != 1)
		sort_three_a(a_stack);
	while (ft_lstsize_ps(*b_stack) > 0)
		pa(a_stack, b_stack);
}
