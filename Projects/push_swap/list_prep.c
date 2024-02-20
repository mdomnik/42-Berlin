/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_prep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:20:21 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/20 01:20:33 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*pop_stack(t_stack *a_stack, int argc, char **argv)
{
	t_stack	*new;
	int		i;

	new = NULL;
	i = 1;
	if (argc <= 1)
		exit (1);
	else
	{
		while (argv[i])
		{
			if (errors(argv[i]) == 1 || (ft_atoi_ps(argv[i]) > 2147483647)
				|| (ft_atoi_ps(argv[i]) < -2147483648))
				errorescape(a_stack);
			if (error_dup(a_stack, ft_atoi_ps(argv[i])))
				errorescape(a_stack);
			new = ft_lstnew_ps(ft_atoi(argv[i]));
			ft_lstadd_back_ps(&a_stack, new);
			i++;
		}
	}
	return (a_stack);
}

int	handle_errors(t_stack *a_stack, char *temp)
{
	if (error_dup(a_stack, ft_atoi_ps(temp)) || errors(temp) == 1
		|| (ft_atoi_ps(temp) > 2147483647)
		|| (ft_atoi_ps(temp) < -2147483648))
		return (1);
	return (0);
}

t_stack	*pop_stack_string(char **argv, t_stack *a_stack)
{
	t_stack	*new;
	char	**temp;
	int		i;

	i = 0;
	temp = ft_split_ps(argv[1], ' ');
	if (!temp || argv[1] == NULL || argv[1][0] == '\0')
	{
		errorescape(a_stack);
		return (a_stack);
	}
	while (temp[i])
	{
		if (handle_errors(a_stack, temp[i]))
		{
			freetemp(temp);
			errorescape(a_stack);
		}
		new = ft_lstnew_ps(ft_atoi(temp[i]));
		ft_lstadd_back_ps(&a_stack, new);
		i++;
	}
	freetemp(temp);
	return (a_stack);
}

t_stack	*ft_lstnew_ps(int content)
{
	t_stack	*element;

	element = (t_stack *)malloc(sizeof(t_stack));
	if (!element)
		return (NULL);
	element->data = content;
	element->cost = 2147483647;
	element->next = NULL;
	element->opnum = 2147483647;
	element->prev = NULL;
	element->neighbor = NULL;
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
