/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:50:37 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/17 17:16:38 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	
	t_stack *a_stack;
	t_stack *b_stack;

	a_stack = NULL;
	b_stack = NULL;
	if (argc == 2)
		a_stack = pop_stack_string(argv, a_stack);
	else
		a_stack = pop_stack(a_stack, argc, argv);
	if (check_sort(a_stack) != 1)
	{
		if (ft_lstsize_ps(a_stack) == 2)
			sa(&a_stack);
		else if (ft_lstsize_ps(a_stack) == 3)
			sort_three(&a_stack);
		else
			push_swap(&a_stack, &b_stack);
	}
	return (0);
}

void print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
        ft_printf("%d ", stack->data);
        stack = stack->next;
	}
	ft_printf("\n");
}