/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:42:46 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/20 00:51:44 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cheapest_operation(t_stack **a_stack, t_stack **b_stack, t_stack *low)
{
	if ((low->cost >= 0) && (low->neighbor->cost >= 0))
		rr_sort(a_stack, b_stack, low);
	else if ((low->cost <= 0) && (low->neighbor->cost <= 0))
		rrr_sort(a_stack, b_stack, low);
	else if ((low->cost <= 0) && (low->neighbor->cost >= 0))
		rrarb_sort(a_stack, b_stack, low);
	else if ((low->cost >= 0) && (low->neighbor->cost <= 0))
	{
		rarrb_sort(a_stack, b_stack, low);
	}
	if ((*b_stack)->data < (*b_stack)->next->data)
		sb(b_stack);
}

void	rr_sort(t_stack **a_stack, t_stack **b_stack, t_stack *low)
{
	int	i;
	int	j;

	i = low->cost;
	j = low->neighbor->cost;
	while (i > 0 && j > 0)
	{
		rr(a_stack, b_stack);
		j--;
		i--;
	}
	while (i > 0)
	{
		ra(a_stack);
		i--;
	}
	while (j > 0) 
	{
		rb(b_stack);
		j--;
	}
	pb(a_stack, b_stack);
}

void	rrr_sort(t_stack **a_stack, t_stack **b_stack, t_stack *low)
{
	int	i;
	int	j;

	i = low->cost;
	j = low->neighbor->cost;
	while (i < 0 && j < 0)
	{
		rrr(a_stack, b_stack);
		j++;
		i++;
	}
	while (i < 0)
	{
		rra(a_stack);
		i++;
	}
	while (j < 0) 
	{
		rrb(b_stack);
		j++;
	}
	pb(a_stack, b_stack);
}

void	rrarb_sort(t_stack **a_stack, t_stack **b_stack, t_stack *low)
{
	int	i;
	int	j;

	i = low->cost;
	j = low->neighbor->cost;
	while (i < 0)
	{
		rra(a_stack);
		i++;
	}
	while (j > 0) 
	{
		rb(b_stack);
		j--;
	}
	pb(a_stack, b_stack);
}

void	rarrb_sort(t_stack **a_stack, t_stack **b_stack, t_stack *low)
{
	int	i;
	int	j;

	i = low->cost;
	j = low->neighbor->cost;
	while (i > 0)
	{
		ra(a_stack);
		i--;
	}
	while (j < 0) 
	{
		rrb(b_stack);
		j++;
	}
	pb(a_stack, b_stack);
}
