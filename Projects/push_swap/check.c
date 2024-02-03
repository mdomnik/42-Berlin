/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:18:42 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/03 19:24:18 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_sort(t_stack *a_stack)
{
	t_stack	*clone;

	clone = a_stack;
	while (clone->next != NULL)
	{
		if (clone->data <= clone->next->data)
			clone = clone->next;
		else
			return (0);
	}
	return(1);
}

int	ft_lstsize_ps(t_stack *lst)
{
	t_stack	*temp;
	int		i;

	temp = lst;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
