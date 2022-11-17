/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:57:25 by htsang            #+#    #+#             */
/*   Updated: 2022/11/17 03:30:38 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
** @param str: a NULL-terminated string
** @return the length of the given string
*/
static size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

/**
** @brief Copy a part of the source string to the destination string.
**
** @param dest:    a NULL-terminated string to copy to.
** @param src:     a NULL-terminated string to copy from.
** @param start:   the starting index to cut from the source string
** @param max_len: the maximum length to cut from the source string
** @return the destination string
*/
char	*ft_cutstr(char *dest, char *src, size_t start, size_t max_len)
{
	char	*dest_start;

	dest_start = dest;
	ft_strncpy(dest_start, src + start, max_len + 1);
	dest_start[max_len + 1] = 0;
	return (dest_start);
}

/**
** @brief Duplicates a string to a new memory address.
**
** @param str: a NULL-terminated stirng
** @return the new string after duplication from the given string
*/
char	*ft_strdup(const char *str)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(str);
	copy = (char *) malloc(len + 1);
	if (!copy)
	{
		return (NULL);
	}
	ft_strncpy(copy, str, len + 1);
	return (copy);
}

/**
** @brief Append a string of length to the end of the target string.
**
** @param target: the target NULL-terminated string to append to,
** this memory address will be freed.
** @param str: the NULL-terminated string to be appended.
** @return a new target string after concatenation.
*/
char	*ft_strljoin(char *target, char const *str, size_t len)
{
	size_t	s1_len;
	char	*new_str;

	if (!target)
	{
		return (ft_strdup(str));
	}
	s1_len = ft_strlen(target);
	new_str = (char *) malloc(s1_len + len + 1);
	if (!new_str)
	{
		return (NULL);
	}
	ft_strncpy(new_str, target, s1_len);
	ft_strncpy(new_str + s1_len, str, len + 1);
	free(target);
	return (new_str);
}
