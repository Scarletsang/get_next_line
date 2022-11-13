/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:09:04 by htsang            #+#    #+#             */
/*   Updated: 2022/11/13 23:21:26 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	find_line_length(char *cursor)
{
	ssize_t	buffer_size;

	buffer_size = 0;
	while (buffer_size < BUFFER_SIZE)
	{
		if (cursor[buffer_size] == '\n')
		{
			return (buffer_size + 1);
		}
		buffer_size++;
	}
	return (0);
}

static char	*get_line(char **cursor, ssize_t len)
{
	char	*line;

	line = malloc(len + 1);
	if (!line)
	{
		return (NULL);
	}
	*cursor = copy_line(*cursor, line, len);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*cursor = NULL;
	ssize_t		read_len;
	ssize_t		prev_len;
	ssize_t		line_len;

	prev_len = 0;
	read_len = read(fd, cursor, BUFFER_SIZE);
	while (read_len > 0)
	{
		line_len = find_line_length(cursor);
		if (line_len > 0)
		{
			return (get_line(&cursor, line_len + prev_len));
		}
		prev_len += BUFFER_SIZE;
		read_len = read(fd, cursor + prev_len, BUFFER_SIZE);
	}
	return (NULL);
}
