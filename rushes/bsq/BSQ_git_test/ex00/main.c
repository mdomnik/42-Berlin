/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:31:08 by mdomnik           #+#    #+#             */
/*   Updated: 2023/09/13 23:31:14 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	row_len(char **mtrx)
{
	int	i;

	i = 0;
	while (mtrx[i])
	{
		i++;
	}
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		c++;
		i++;
	}
	return (c);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

struct s_map
{
	struct s_charactes		chars;
	int				max_columns;
	int				max_lines;
	char				file_path*;
	char				map**;
};

struct s_charactes
{
	char	length;
	char	empty;
	char	obstacle;
	char	full;
};

void	execute(struct s_map map_info)
{
	map_info.max_lines = get_max_lines(map_info.file_path);
	map_info.max_columns = get_max_columns(map_info.file_path);
	printf("lines: %i\ncolumns: %i\n", map_info.max_lines, map_info.max_columns);
	map_info.map = allocate_mda(map_info.max_lines, map_info.max_columns);
	save_map(map_info.map, map_info.file_path);
	check(map_info.map, map_info.max_lines, map_info.max_columns, 0);
	print_mda(map_info.map, map_info.max_lines, map_info.max_columns);
	free_mda(map_info.map, map_info.max_lines);
}

int	main(int argc, char **argv)
{
	struct s_map	map_info;
	int				i;

	if (argc < 2 || argv[1][0] == '\0')
	{
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		map_info.file_path = malloc(ft_strlen(argv[i]) * sizeof(char));
		if (!map_info.file_path)
		{
			free(map_info.file_path);
			return (0);
		}
		ft_strcpy(map_info.file_path, argv[i]);
		printf("path: %s\n", map_info.file_path);
		execute(map_info);
		i++;
	}
	return (0);
}
