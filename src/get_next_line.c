/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:09:04 by htsang            #+#    #+#             */
/*   Updated: 2022/11/17 03:10:31 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	find_line_end(char *str)
{
	size_t	len;

	len = 1;
	while (str[len])
	{
		if (str[len] == '\n')
		{
			return (len);
		}
		len++;
	}
	return (0);
}

static char	*main_logic(int fd, char leftover[BUFFER_SIZE])
{
	char	*buff;
	char	*current;
	ssize_t	read_len;
	size_t	line_len;

	current = NULL;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	read_len = read(fd, buff, BUFFER_SIZE);
	while (read_len > 0)
	{
		buff[read_len] = 0;
		line_len = find_line_end(buff);
		if (line_len)
		{
			ft_cutstr(leftover, buff, line_len + 1, read_len - line_len);
			current = ft_strljoin(current, buff, line_len);
			return (free(buff), current);
		}
		current = ft_strljoin(current, buff, line_len);
		read_len = read(fd, buff, BUFFER_SIZE);
	}
	return (free(buff), current);
}

char	*get_next_line(int fd)
{
	static char	leftover[BUFFER_SIZE + 1];
	size_t		line_len;

	if (leftover[0])
	{
		line_len = find_line_end(leftover);
		if (line_len)
		{
			ft_cutstr(leftover, leftover, \
			line_len + 1, BUFFER_SIZE - line_len);
			if (leftover[0])
				return (ft_strdup(leftover));
			return (NULL);
		}
		return (ft_strljoin(NULL, leftover, line_len + 1));
	}
	return (main_logic(fd, leftover));
}
