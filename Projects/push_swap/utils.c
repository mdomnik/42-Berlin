/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:32:18 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/20 01:11:19 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	if (*stack == NULL)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	push(t_stack **stack, t_stack **node)
{
	t_stack	*push_node;

	if (node == NULL)
		return ;
	push_node = *node;
	*node = (*node)->next;
	if (*node)
		(*node)->prev = NULL;
	push_node->prev = NULL;
	if (*stack == NULL)
	{
		*stack = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *stack;
		push_node->next->prev = push_node;
		*stack = push_node;
	}
}

void	rev_rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*head;
	t_stack	*onebeforetail;

	head = *stack;
	tail = ft_lstlast_ps(*stack);
	onebeforetail = tail->prev;
	ft_lstadd_front_ps(stack, tail);
	(*stack)->next = head;
	onebeforetail->next = NULL;
}

void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*second;
	t_stack	*tail;

	head = *stack;
	second = (*stack)->next;
	tail = ft_lstlast_ps(*stack);
	ft_lstadd_back_ps(&second, head);
	if (second && second->next)
	{
		second->prev = NULL;
		head->prev = tail;
		head->next = NULL;
		*stack = second;
	}
}

void	ft_lstadd_front_ps(t_stack **lst, t_stack *new)
{
	t_stack	*head;

	head = *lst;
	if (lst)
	{
		if (head)
		{
			new->next = head;
			head->prev = new;
		}
		new->prev = NULL;
		*lst = new;
	}
	new->next = lst[0];
	*lst = new;
}
