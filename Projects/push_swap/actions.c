/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:42:46 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/19 04:28:08 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *cheapest_operation(t_stack *a_stack, t_stack *b_stack, t_stack *low)
{
    t_stack *temp;
    temp = a_stack;

    while (temp != NULL && temp->opnum != low->opnum)
        temp = temp->next;

    if (temp != NULL) {
        if ((temp->cost > 0) && (temp->neighbor->cost > 0))
            rr_sort(temp, b_stack);
        else if ((temp->cost < 0) && (temp->neighbor->cost < 0))
            rrr_sort(temp, b_stack);
        else if ((temp->cost < 0) && (temp->neighbor->cost > 0))
            rrarb_sort(temp, b_stack);
        else if ((temp->cost > 0) && (temp->neighbor->cost < 0))
            rarrb_sort(temp, b_stack);
    }

    return temp;
}


void rr_sort(t_stack *a_stack, t_stack *b_stack)
{
	int i;
	int	j;

	i = a_stack->cost;
	j = i;
	if (a_stack->neighbor->cost < i)
		i = a_stack->neighbor->cost;
	if (a_stack->neighbor->cost > i)
		j = a_stack->neighbor->cost;
	while(i > 0)
	{
		rr(&a_stack, &b_stack);
		j--;
		i--;
	}
	while (j > 0) 
	{	
		if (a_stack->neighbor->cost > a_stack->cost)
			rb(&b_stack);
		if (a_stack->neighbor->cost < a_stack->cost)
			ra(&a_stack);
		j--;
	}
	pb(&a_stack, &b_stack);
}

void rrr_sort(t_stack *a_stack, t_stack *b_stack)
{
	int i;
	int	j;

	i = a_stack->cost;
	j = i;
	if (a_stack->neighbor->cost < i)
		i = a_stack->neighbor->cost;
	if (a_stack->neighbor->cost > i)
		j = a_stack->neighbor->cost;
	while(i > 0)
	{
		rrr(&a_stack, &b_stack);
		j--;
		i--;
	}
	while (j > 0) 
	{	
		if (a_stack->neighbor->cost < a_stack->cost)
			rrb(&b_stack);
		if (a_stack->neighbor->cost > a_stack->cost)
			rra(&a_stack);
		j--;
	}
	pb(&a_stack, &b_stack);
}

void rrarb_sort(t_stack *a_stack, t_stack *b_stack)
{
	int i;
	int	j;

	i = a_stack->cost;
	j = i;
	if (a_stack->neighbor->cost < i)
		i = a_stack->neighbor->cost;
	if (a_stack->neighbor->cost > i)
		j = a_stack->neighbor->cost;
	while(i > 0)
	{
		rra(&a_stack);
		rb(&b_stack);
		j--;
		i--;
	}
	while (j > 0) 
	{	
		if (a_stack->neighbor->cost < a_stack->cost)
			rra(&b_stack);
		if (a_stack->neighbor->cost > a_stack->cost)
			rb(&a_stack);
		j--;
	}
	pb(&a_stack, &b_stack);
}

void rarrb_sort(t_stack *a_stack, t_stack *b_stack)
{
	int i;
	int	j;

	i = a_stack->cost;
	j = i;
	if (a_stack->neighbor->cost < i)
		i = a_stack->neighbor->cost;
	if (a_stack->neighbor->cost > i)
		j = a_stack->neighbor->cost;
	while(i > 0)
	{
		ra(&a_stack);
		rrb(&b_stack);
		j--;
		i--;
	}
	while (j > 0) 
	{	
		if (a_stack->neighbor->cost < a_stack->cost)
			ra(&b_stack);
		if (a_stack->neighbor->cost > a_stack->cost)
			rrb(&a_stack);
		j--;
	}
	pb(&a_stack, &b_stack);
}