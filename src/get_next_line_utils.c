/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:57:25 by htsang            #+#    #+#             */
/*   Updated: 2022/11/17 03:07:17 by htsang           ###   ########.fr       */
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
	while (*src && start)
	{
		src++;
		start--;
	}
	ft_strncpy(dest_start, src, max_len + 1);
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
** @brief Join two strings into a new memory. The second string
** is concatenated after the first string. It is equivalence
** to the "concat" function in other programming languages.
**
** @param s1: the 1st NULL-terminated string
** @param s2: the 2nd NULL-terminated string
** @return a new memory address storing the string after
** concatenation of the 2 original strings. NULL is returned if
** malloc fails.
*/
char	*ft_strljoin(char *s1, char const *s2, size_t len)
{
	size_t	s1_len;
	char	*ptr;

	if (!s1)
	{
		s1 = "";
	}
	s1_len = ft_strlen(s1);
	ptr = (char *) malloc(s1_len + len + 1);
	if (!ptr)
	{
		return (NULL);
	}
	ft_strncpy(ptr, s1, s1_len);
	ft_strncpy(ptr + s1_len, s2, len + 1);
	return (ptr);
}
