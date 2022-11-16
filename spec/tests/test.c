/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:27:00 by htsang            #+#    #+#             */
/*   Updated: 2022/11/16 14:39:59 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	get_n_line_fd(test_func func, int fd, size_t n)
{
	char	*str;

	printf("\ngetting lines from the fd: %d\n", fd);
	while (n)
	{
		str = func(fd);
		printf("return: [%s]", str);
		free(str);
		n--;
	}
	close(fd);
}

void	get_n_line(test_func func, const char *file_name, size_t n)
{
	int fd;

	fd = open(file_name,  O_RDONLY);
	get_n_line_fd(func, fd, n);
}
