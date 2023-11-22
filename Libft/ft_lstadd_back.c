/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:04:03 by mdomnik           #+#    #+#             */
/*   Updated: 2023/11/20 17:26:24 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	int		i;
	t_list	*temp;

	i = 0;
	if (lst[0] == NULL)
		lst[0] = new;
	else
	{
		temp = lst[0];
		while (temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = new;
	}
}
