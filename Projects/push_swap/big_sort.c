/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:30:48 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/20 01:25:57 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		lstsize;

	i = 0;
	lstsize = ft_lstsize_ps(*stack_a);
	if (lstsize > 6)
	{
		while (i++ < 3 && (check_sort(*stack_a) != 1)
			&& ft_lstsize_ps(*stack_a) > 3)
			pb(stack_a, stack_b);
		sort_three_b(stack_b);
		if (ft_lstsize_ps(*stack_a) > 3 && (check_sort(*stack_a) != 1))
			sort_b_stack(stack_a, stack_b);
	}
	else
		sort_low(stack_a, stack_b);
}

void	perform_operations(t_stack **stack_a, t_stack **stack_b, t_stack **temp)
{
	pop_cost_a(stack_a);
	pop_cost_b(stack_b);
	*temp = closest_val(*temp, *stack_b);
	lowest_operator(*temp);
	if (ft_lstsize_ps(*stack_a) > 1)
		*temp = get_head(*stack_a);
	else
		*temp = (*stack_a);
}

void	sort_b_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*low;
	int		lstsize;

	temp = *stack_a;
	while (ft_lstsize_ps(*stack_a) > 0)
	{
		lstsize = ft_lstsize_ps(temp);
		perform_operations(stack_a, stack_b, &temp);
		low = find_lowest(temp);
		cheapest_operation(stack_a, stack_b, low);
		if (ft_lstsize_ps(*stack_a) > 1)
			temp = get_head(*stack_a);
		else
			temp = (*stack_a);
	}
	final_sort(stack_a, stack_b);
}

void	pop_cost_a(t_stack **stack_a)
{
	t_stack	*temp;
	int		index;
	int		lstsize;

	index = 0;
	temp = *stack_a;
	lstsize = ft_lstsize_ps(temp);
	while (temp != NULL)
	{
		temp->index = index;
		if ((lstsize / 2) >= temp->index)
			temp->cost = temp->index;
		else
			temp->cost = temp->index - (lstsize);
		index++;
		temp = temp->next;
	}
}

int	find_pos(t_stack *stack, int num)
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
