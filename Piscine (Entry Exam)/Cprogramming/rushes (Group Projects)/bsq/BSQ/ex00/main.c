/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarzt <jarzt@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:35:24 by jarzt             #+#    #+#             */
/*   Updated: 2023/09/12 10:35:25 by jarzt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_header.h"
# include <stdio.h>

int	main()
{
	char **map;
	char file_path[] = "map.dict";
	int	lines = 10;
	int rows = 20;

	map = allocate_mda(lines, rows);
	save_map(map, file_path);
	check(map, rows, lines);
	print_mda(map, lines, rows);


	//cycle through all starting positions (x,y)
	// if square made from that position is smaller, just increment the y
	//if its at lowest y, reset y, increment x
	// if a bigger square is found, update the new starting position
	// is same size square is found dont update position
	//after checking all pos, fill the square of size i from the biggest found position
	
	return (0);
}