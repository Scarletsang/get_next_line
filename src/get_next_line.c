/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:09:04 by htsang            #+#    #+#             */
/*   Updated: 2022/11/14 20:57:36 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*save_leftover(char **leftover, char *buff, ssize_t len)
{
	char	*new_leftover;

	if (*leftover)
	{
		free(*leftover);
	}
	new_leftover = malloc(sizeof(char) * len + 1);
	if (!new_leftover)
	{
		return (NULL);
	}
	return (ft_strlcpy(new_leftover, buff, len));
}

static char	*join_current(char **current, char *buff, \
int iteration, ssize_t len)
{
	char	*new_current;
	ssize_t	prev_len;

	prev_len = iteration * BUFFER_SIZE;
	new_current = malloc(sizeof(char) * (prev_len + len + 1));
	if (!new_current)
	{
		return (NULL);
	}
	ft_strlcpy(new_current, *current, iteration * BUFFER_SIZE);
	ft_strlcpy(new_current + prev_len, buff, len);
	free(*current);
	return (new_current);
}

static char	*find_next_line_pos(ssize_t *read_len, char buff[BUFFER_SIZE])
{
	if (*read_len < BUFFER_SIZE)
	{
		return (buff + *read_len);
	}
	else
	{
		return (ft_strchr(buff, '\n'));
	}
}

static char	*main_logic(int fd, char **current, char **leftover)
{
	char	buff[BUFFER_SIZE + 1];
	int		iteration;
	ssize_t	read_len;
	char	*next_line_pos;

	iteration = 0;
	read_len = read(fd, buff, BUFFER_SIZE);
	while (read_len)
	{
		next_line_pos = find_next_line_pos(&read_len, buff);
		if (next_line_pos)
		{
			*leftover = save_leftover(leftover, next_line_pos, \
				read_len - (next_line_pos - buff));
			*current = join_current(current, buff, \
				iteration, next_line_pos - buff);
			return (*current);
		}
		iteration++;
		*current = join_current(current, buff, iteration, BUFFER_SIZE);
		read_len = read(fd, buff, BUFFER_SIZE);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*leftover = NULL;
	char		*current;

	current = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!current)
	{
		return (NULL);
	}
	if (leftover)
	{
		current = ft_strdup(leftover);
	}
	return (main_logic(fd, &current, &leftover));
}
