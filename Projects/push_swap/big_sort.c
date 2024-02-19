/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:30:48 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/19 04:25:24 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
	int		i;

	i = 0;
	temp = (*stack_a)->next;
	while (i++ < 3 && (check_sort(*stack_a) != 1) && ft_lstsize_ps(*stack_a) > 3)
		pb(stack_a, stack_b);
	if (ft_lstsize_ps(*stack_a) > 3 && (check_sort(*stack_a) != 1))
		sort_b_stack(stack_a, stack_b);
	// if (check_sort(*stack_a) != 1)
	// 	sort_three_a(stack_a);
}

void sort_b_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
	int		lstsize;
	t_stack	*low;

	low = *stack_a;
	temp = *stack_a;
	while (ft_lstsize_ps(temp) > 3)
	{
			temp = *stack_a;
			lstsize = ft_lstsize_ps(temp);
			// printf("lstsize %d\n", ft_lstsize_ps(temp));
			pop_cost_a(temp);
			pop_cost_b(*stack_b);
			temp = closest_val(temp, *stack_b);
			lowest_operator(temp);
			low = find_lowest(temp);
			printf("add: %p\n", temp->next);
			temp = cheapest_operation(temp, *stack_b, low);
			printf("Lowest: val[%d], cost[%d], nval[%d], ncost[%d], opnum[%d]\n", low->data, low->cost, low->neighbor->data, low->neighbor->cost, low->opnum);
			printf("ls [%d], val [%d], idx [%d], cst [%d], nei: [%d], neic [%d], lo [%d]\n", lstsize, temp->data, temp->index, temp->cost, temp->neighbor->data, temp->neighbor->cost, temp->opnum);
			printf("lowest [%d moves]\n", low->opnum);
			printf("add: %p\n", temp->next);
			printf("stack: %p\n", (*stack_a)->next);
			temp = *stack_a;
	}
}

void pop_cost_a(t_stack *stack_a)
{
	t_stack *temp;
	int		index;
	int		lstsize;

	index = 0;
	temp = stack_a;
	lstsize = ft_lstsize_ps(temp);
	while (temp != NULL)
	{
		temp->index = index;
		if ((lstsize / 2) >= temp->index)
			temp->cost = temp->index + 1;
		else
			temp->cost = temp->index - (lstsize + 1);
		index++;
		temp = temp->next;
	}
}



int find_pos(t_stack *stack, int num)
{
	int	pos;
	
	pos = 0;
	while (stack->data != num)
	{
		pos++;
		stack = stack->next;
	}
	stack->index = 0;
	return (pos);
}

