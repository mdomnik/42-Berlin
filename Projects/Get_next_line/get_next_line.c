/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:27:27 by mdomnik           #+#    #+#             */
/*   Updated: 2023/12/05 12:18:58 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*find_line(int fd, char *keep, char *buffer);
static char	*prep_next(char *buffer);

char	*get_next_line(int fd)
{
	char		*buf;
	char		*str;
	static char	*keep;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(keep);
		free(buf);
		keep = NULL;
		return (0);
	}
	if (!buf)
		return (NULL);
	str = find_line(fd, keep, buf);
	free(buf);
	if (!str)
		return (NULL);
	keep = prep_next(str);
	return (str);
}

static char	*find_line(int fd, char *keep, char *buffer)
{
	ssize_t	bytes_read;
	char	*tempy;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(keep);
			return (0);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		if (!keep)
			keep = ft_strdup("");
		tempy = keep;
		keep = ft_strjoin(tempy, buffer);
		free(tempy);
		if (ft_strchr (buffer, '\n'))
			break ;
	}
	return (keep);
}

static char	*prep_next(char *buffer)
{
	char	*keep;
	ssize_t	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == 0)
		return (NULL);
	keep = ft_substr(buffer, i + 1, ft_strlen(buffer) - i);
	if (*keep == 0)
	{
		free(keep);
		keep = NULL;
	}
	buffer[i + 1] = 0;
	return (keep);
}
