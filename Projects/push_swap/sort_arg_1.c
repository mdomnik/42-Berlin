/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:47:22 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/18 21:31:12 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_stack **stack_a)
{
	t_stack *high;
	
	high = get_high_val(*stack_a);
	if (*stack_a == high)
		ra(stack_a);
	else if((*stack_a)->next == high)
		rra(stack_a);
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a);
}

void	sort_three_b(t_stack **stack_b)
{
	t_stack *low;
	
	low = get_low_val(*stack_b);
	if (*stack_b == low)
		rb(stack_b);
	else if((*stack_b)->next == low)
		rrb(stack_b);
	if ((*stack_b)->data < (*stack_b)->next->data)
		sb(stack_b);
}

t_stack *get_high_val(t_stack *stack)
{
	t_stack	*high;
	t_stack	*hightwo;
	int		high_num;

	high = stack;
	hightwo = stack;
	high_num = high->data;
	while (high)
	{
		if(high_num < high->data)
			high_num = high->data;
		high = high->next;
	}
	while (hightwo)
	{
		if(hightwo->data == high_num)
			return(hightwo);
		else
			hightwo = hightwo->next;
	}
	return (0);
}

t_stack *get_low_val(t_stack *stack)
{
	t_stack	*low;
	t_stack	*lowtwo;
	int		low_num;

	low = stack;
	lowtwo = stack;
	low_num = low->data;
	while (low)
	{
		if(low_num > low->data)
			low_num = low->data;
		low = low->next;
	}
	while (lowtwo)
	{
		if(lowtwo->data == low_num)
			return(lowtwo);
		else
			lowtwo = lowtwo->next;
	}
	return (0);
}


