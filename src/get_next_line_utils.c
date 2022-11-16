/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:57:25 by htsang            #+#    #+#             */
/*   Updated: 2022/11/16 14:20:09 by htsang           ###   ########.fr       */
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
** @brief Cut a substring out of a given string by its starting index
** and length. Th substring is stored in a new memory address. The
** original string is left untouched.
**
** @param str:     a NULL-terminated string to cut the string from.
** @paarm start:   the starting index to cut from the string
** @param max_len: the maximum length to cut from the string
** @return the newly created substring
*/
char	*ft_substr(char const *str, unsigned int start, size_t max_len)
{
	char	*ptr;
	size_t	possible_size;

	if (!str)
		return (NULL);
	while (*str && start)
	{
		str++;
		start--;
	}
	possible_size = ft_strlen(str);
	if (max_len + start > possible_size)
		max_len = possible_size;
	ptr = (char *) malloc(max_len + 1);
	if (!ptr)
		return (NULL);
	ft_strncpy(ptr, str, max_len + 1);
	ptr[max_len + 1] = 0;
	return (ptr);
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
	if (s1[0])
		free(s1);
	return (ptr);
}
