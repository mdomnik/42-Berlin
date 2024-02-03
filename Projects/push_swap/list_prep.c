/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_prep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:20:21 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/03 19:04:23 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *pop_stack(t_stack *a_stack, int argc, char **argv)
{
	t_stack	*new;
	int	i;
	
	new = NULL;
	i = 1;
	if (argc <= 1)
		exit (1);
	else
	{
		while (argv[i])
		{
			new = ft_lstnew_ps(ft_atoi(argv[i]));
			ft_lstadd_back_ps(&a_stack, new);
			i++;
		}
	}
	return (a_stack);
}

t_stack *pop_stack_string(char **argv, t_stack *a_stack)
{
	t_stack *new;
	char	**temp;
	int		i;

	i = 0;
	temp = argv;
	temp = ft_split(argv[1], ' ');
	while (temp[i])
	{
		new = ft_lstnew_ps(ft_atoi(temp[i]));
		ft_lstadd_back_ps(&a_stack, new);
		i++;
	}
	free(temp);
	return(a_stack);
}

t_stack	*ft_lstnew_ps(int	content)
{
	t_stack	*element;

	element = (t_stack *)malloc(sizeof(t_stack));
	if (!element)
		return (NULL);
	element->data = content;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	last = ft_lstlast_ps(*lst);
	if (!last)
	{
		*lst = new;
		new->prev = NULL;
	}
	else
	{
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}

}

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	t_stack	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}
