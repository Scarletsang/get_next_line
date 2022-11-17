/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:09:04 by htsang            #+#    #+#             */
/*   Updated: 2022/11/17 14:23:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	find_line_end(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		if (str[len] == '\n')
		{
			return (len + 1);
		}
		len++;
	}
	return (0);
}

static char	*free_current(char *current)
{
	if (current)
	{
		free(current);
	}
	return (NULL);
}

static char	*main_logic(int fd, char *current, char leftover[BUFFER_SIZE])
{
	char	*buff;
	ssize_t	read_len;
	size_t	line_len;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free_current(current));
	read_len = read(fd, buff, BUFFER_SIZE);
	while (read_len > 0)
	{
		buff[read_len] = 0;
		line_len = find_line_end(buff);
		if (line_len)
		{
			ft_cutstr(leftover, buff, line_len, read_len - line_len);
			current = ft_strljoin(current, buff, line_len);
			return (free(buff), current);
		}
		current = ft_strljoin(current, buff, read_len);
		read_len = read(fd, buff, BUFFER_SIZE);
	}
	leftover[0] = 0;
	return (free(buff), current);
}

char	*get_next_line(int fd)
{
	static char	leftover[BUFFER_SIZE + 1];
	char		*current;
	size_t		line_len;

	if (leftover[0])
	{
		line_len = find_line_end(leftover);
		if (line_len)
		{
			current = ft_strljoin(NULL, leftover, line_len);
			ft_cutstr(leftover, leftover, \
				line_len + 1, BUFFER_SIZE - line_len);
			return (current);
		}
		current = ft_strdup(leftover);
		if (!current)
		{
			return (NULL);
		}
		return (main_logic(fd, current, leftover));
	}
	return (main_logic(fd, NULL, leftover));
}
