/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:27:27 by mdomnik           #+#    #+#             */
/*   Updated: 2023/12/04 15:13:55 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *read_file(int fd);

char	*get_next_line(int fd)
{
	char *buf;

	printf("if you dont work idk");
	buf = read_file(fd);
	if (!buf)
		return (NULL);
	
	return (buf);
}

static char *read_file(int fd)
{
	int  bytes_read;
	char *buffer;
	char *temp;

  buffer = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
  if (!buffer)
    return (NULL);
  bytes_read = read(fd, buffer, BUFFER_SIZE);
  printf("bytes biting?");
  if (bytes_read <= 0)
  {
	free (buffer);
    return (NULL);
  }
	if (ft_strchr(buffer, '\n') == NULL)
	{
		printf("peeepo browkien?");
		temp = ft_strjoin(temp, buffer);
	}
	else
	{
		printf("do something!!");
	}
  return (buffer);
}