/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:09:04 by htsang            #+#    #+#             */
/*   Updated: 2022/11/16 14:24:03 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_leftover(char **leftover)
{
	free(*leftover);
	*leftover = NULL;
	return (NULL);
}

static char	*ft_substr_free(char *str, size_t start, size_t len)
{
	char	*new;

	new = ft_substr(str, start, len);
	free(str);
	return (new);
}

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

static char	*main_logic(int fd, char **leftover)
{
	char	*buff;
	char	*current;
	ssize_t	read_len;
	size_t	line_len;

	current = *leftover;
	buff = malloc(BUFFER_SIZE + 1);
	read_len = read(fd, buff, BUFFER_SIZE);
	while (read_len > 0)
	{
		buff[read_len] = 0;
		line_len = find_line_end(buff);
		if (line_len)
		{
			*leftover = ft_substr(buff, line_len + 1, read_len - line_len);
			if (!*leftover)
				return (free(buff), free_leftover(leftover));
			if ((*leftover)[0] == 0)
				free_leftover(leftover);
			return (free(buff), ft_strljoin(current, buff, line_len));
		}
		current = ft_strljoin(current, buff, line_len);
		read_len = read(fd, buff, BUFFER_SIZE);
	}
	return (free(buff), current);
}

char	*get_next_line(int fd)
{
	static char	*leftover = NULL;
	char		*current;
	size_t		line_len;

	if (leftover)
	{
		line_len = find_line_end(leftover);
		if (line_len)
		{
			current = ft_substr(leftover, 0, line_len);
			if (!current)
			{
				return (NULL);
			}
			leftover = ft_substr_free(leftover, \
			line_len + 1, BUFFER_SIZE - line_len);
			if (leftover && leftover[0])
				return (current);
			return (free_leftover(&leftover));
		}
		current = ft_strljoin(NULL, leftover, line_len + 1);
		free_leftover(&leftover);
		return (current);
	}
	return (main_logic(fd, &leftover));
}
