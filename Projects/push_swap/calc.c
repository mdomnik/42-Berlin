/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:13:10 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/19 03:00:21 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *closest_neighbor_node(t_stack *stack_b, t_stack *element) 
{
	t_stack *temp_b = stack_b;
	t_stack *closest_neighbor;
	int closest_diff;
	int current_diff;
	
	temp_b = stack_b;
	closest_neighbor = NULL;
	closest_diff = 2147483647;
	while (temp_b != NULL) 
	{
		current_diff = temp_b->data - element->data;
		if (current_diff < 0)
			current_diff = -current_diff;
		if (current_diff < closest_diff)
		{
			closest_diff = current_diff;
			closest_neighbor = temp_b;
		}
		temp_b = temp_b->next;
	}
	return closest_neighbor;
}

t_stack *closest_val(t_stack *stack_a, t_stack *stack_b) {
	t_stack *temp_a;
	t_stack *closest_neighbor;
	
	temp_a = stack_a;
	closest_neighbor = NULL;
	while (temp_a != NULL) {
		closest_neighbor = closest_neighbor_node(stack_b, temp_a);
		temp_a->neighbor = closest_neighbor;
		temp_a = temp_a->next;
	}
	return stack_a;
}

void pop_cost_b(t_stack *stack_b)
{
	t_stack *temp;
	int		index;
	int		lstsize;

	index = 0;
	temp = stack_b;
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

void lowest_operator(t_stack *stack)
{
	t_stack *temp;

	temp = stack;
	while(temp != NULL)
	{
		if ((temp->cost > 0) && (temp->neighbor->cost > 0) && (temp->cost > temp->neighbor->cost))
				temp->opnum = temp->cost;
		else if ((temp->cost > 0) && (temp->neighbor->cost > 0) && (temp->cost < temp->neighbor->cost))
				temp->opnum = temp->neighbor->cost;
		else if ((temp->cost < 0) && (temp->neighbor->cost < 0) && (temp->cost < temp->neighbor->cost))
			temp->opnum = temp->cost;
		else if ((temp->cost < 0) && (temp->neighbor->cost < 0) && (temp->cost > temp->neighbor->cost))
			temp->opnum = temp->neighbor->cost;
		else if ((temp->cost < 0) && (temp->neighbor->cost > 0))
			temp->opnum = (temp->neighbor->cost + (temp->cost * (-1)));
		else if ((temp->cost > 0) && (temp->neighbor->cost < 0))
			temp->opnum = ((temp->neighbor->cost * (-1)) + temp->cost);
		else
			temp->opnum = temp->cost;
		temp = temp->next;
	}
}

t_stack *find_lowest(t_stack *stack)
{
	t_stack *temp;
	t_stack	*low;
	int		i;

	temp = stack;
	low = stack;
	while (temp != NULL)
	{
		if (low->opnum < 0)
			i = low->opnum * (-1);
		else
			i = low->opnum;
		if ((temp->opnum > 0) && (temp->opnum < low->opnum))
			low->opnum = temp->opnum;
		else if ((temp->opnum < 0) && (temp->opnum > low->opnum))
			low->opnum = temp->opnum;
		temp = temp->next;
	}
	return (low);
}