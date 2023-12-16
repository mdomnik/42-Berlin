/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:36:29 by mdomnik           #+#    #+#             */
/*   Updated: 2023/09/13 23:36:31 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	check_map(int empty, int obstacle, int full)
{
	if (empty == obstacle || empty == full || obstacle == full)
		return (0);
	return (1);
}
