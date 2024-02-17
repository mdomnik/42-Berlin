/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:47:22 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/17 17:33:39 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	t_stack *high;
	
	high = get_high_val(*stack_a);
	if (*stack_a == high)
		ra(stack_a);
	else if((*stack_a)->next == high)
		rra(stack_a);
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a);
	print_stack(*stack_a);
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

void push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int i = 0;
	pb(stack_a, stack_b);
	while (ft_lstsize_ps(*stack_a) > 0)
	{
		// ft_printf("stack A: ");
		// print_stack(*stack_a);
		// ft_printf("stack B: ");
		// print_stack(*stack_b);
		i = datacmp(*stack_a, *stack_b);
		if (i == 1)
			pb(stack_a, stack_b);
		else if (i == -1)
		{
			while(i == -1)
			{
				if (ft_lstsize_ps(*stack_b) > 1)
				{
					pa(stack_a, stack_b);
					sa(stack_a);
					printf("blyat\n");
				}
				else
				{
					pb(stack_a, stack_b);
					sa(stack_b);
					pa(stack_a, stack_b);
					printf("blyat\n");
					break ;
				}
			}
			pb(stack_a, stack_b);
		}
	}
}

