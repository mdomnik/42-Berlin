/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:50:37 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/20 01:01:38 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	if (argc == 2)
		a_stack = pop_stack_string(argv, a_stack);
	else if (argc > 2)
		a_stack = pop_stack(a_stack, argc, argv);
	else
		return (0);
	if (a_stack == NULL)
		errorescape(a_stack); 
	if (check_sort(a_stack) != 1)
	{
		if (ft_lstsize_ps(a_stack) == 2)
			sa(&a_stack);
		else if (ft_lstsize_ps(a_stack) == 3)
			sort_three_a(&a_stack);
		else
			push_swap(&a_stack, &b_stack);
	}
	ft_free(&a_stack);
}
