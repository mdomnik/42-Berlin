/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:32:18 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/03 20:42:28 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	push(t_stack **stack, t_stack **node)
{
	t_stack *temp;
	
	if (!node)
		return ;
	temp = ft_lstnew_ps((*node)->data);
	ft_lstadd_front_ps(stack, temp);
	if (ft_lstsize_ps(*node) == 0)
	{
		*node = (*node)->next;
		free((*node)->prev);
	}
}

void rev_rotate(t_stack **stack)
{
	t_stack *tail;
	t_stack	*head;
	t_stack	*onebeforetail;
	
	head = *stack;
	tail = ft_lstlast_ps(*stack);
	onebeforetail = tail->prev;
	ft_lstadd_front_ps(stack, tail);
	(*stack)->next = head;
	onebeforetail->next = NULL;
}

void rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack *second;
	t_stack	*tail;
	
	head = *stack;
	second = (*stack)->next;
	tail = ft_lstlast_ps(*stack);
	ft_lstadd_back_ps(&second, head);
	if (second && second->next)
	{
		second->prev = NULL;
		head->prev = tail;
		head->next= NULL;
		*stack = second;
	}
}


void	ft_lstadd_front_ps(t_stack **lst, t_stack *new)
{
	t_stack	*head;

	head = *lst;
	if (lst)
	{
		if(head)
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