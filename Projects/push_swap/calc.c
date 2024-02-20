/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:13:10 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/20 01:49:45 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*closest_neighbor_node(t_stack *stack_b, t_stack *element)
{
	t_stack	*temp_b;
	t_stack	*closest_neighbor;
	int		closest_diff;
	int		current_diff;

	temp_b = stack_b;
	closest_neighbor = NULL;
	closest_diff = 2147483647;
	while (temp_b != NULL) 
	{
		current_diff = temp_b->data - element->data;
		if (current_diff < 0)
			current_diff = -current_diff;
		if (current_diff < closest_diff || (current_diff == closest_diff 
				&& temp_b->data < closest_neighbor->data))
		{
			closest_diff = current_diff;
			closest_neighbor = temp_b;
		}
		temp_b = temp_b->next;
	}
	return (closest_neighbor);
}

t_stack	*closest_val(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp_a;
	t_stack	*closest_neighbor;

	temp_a = stack_a;
	closest_neighbor = NULL;
	while (temp_a != NULL) 
	{
		closest_neighbor = closest_neighbor_node(stack_b, temp_a);
		temp_a->neighbor = closest_neighbor;
		temp_a = temp_a->next;
	}
	return (stack_a);
}

void	pop_cost_b(t_stack **stack_b)
{
	t_stack	*temp;
	int		index;
	int		lstsize;

	index = 0;
	temp = *stack_b;
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

void	assign_opnum(t_stack *temp, int cost, int neicost)
{
	if ((cost >= 0) && (neicost >= 0) && (cost > neicost))
		temp->opnum = cost;
	else if ((cost >= 0) && (neicost >= 0) && (cost < neicost))
		temp->opnum = neicost;
	else if ((cost < 0) && (neicost < 0) && (cost < neicost))
		temp->opnum = cost;
	else if ((cost < 0) && (neicost < 0) && (cost > neicost))
		temp->opnum = neicost;
	else if ((cost < 0) && (neicost >= 0))
		temp->opnum = (neicost + (cost * (-1)));
	else if ((cost >= 0) && (neicost < 0))
		temp->opnum = ((neicost * (-1)) + cost);
	else
		temp->opnum = cost;
}

void	lowest_operator(t_stack *stack)
{
	t_stack	*temp;
	int		cost;
	int		neicost;

	temp = stack;
	while (temp != NULL)
	{
		cost = temp->cost;
		neicost = temp->neighbor->cost;
		assign_opnum(temp, cost, neicost);
		if (temp->opnum < 0)
			temp->opnum *= -1;
		temp = temp->next;
	}
}
