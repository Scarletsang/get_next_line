/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:09:04 by htsang            #+#    #+#             */
/*   Updated: 2022/11/17 04:28:03 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
** @brief Copy a part of the source string to the destination string.
**
** @param dest:    a NULL-terminated string to copy to.
** @param src:     a NULL-terminated string to copy from.
** @param start:   the starting index to cut from the source string
** @param max_len: the maximum length to cut from the source string
** @return the destination string
*/
static char	*ft_cutstr(char *dest, char *src, size_t start, size_t max_len)
{
	char	*dest_start;

	dest_start = dest;
	ft_strncpy(dest_start, src + start, max_len + 1);
	dest_start[max_len + 1] = 0;
	return (dest_start);
}

static size_t	find_line_end(char *str)
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

static char	*init_current(char leftover[BUFFER_SIZE])
{
	if (leftover[0])
	{
		return (ft_strdup(leftover));
	}
	return (NULL);
}

static char	*main_logic(int fd, char leftover[BUFFER_SIZE])
{
	char	*buff;
	char	*current;
	ssize_t	read_len;
	size_t	line_len;

	current = init_current(leftover);
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
	}
	return (main_logic(fd, leftover));
}
