/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:27:00 by htsang            #+#    #+#             */
/*   Updated: 2022/11/13 23:38:01 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test1(const char *file_name)
{
	char	*str;
	int		fd;

	fd = open(file_name, O_RDWR);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	close(fd);
}

void	test2(const char *file_name)
{
	void	*buff;
	int		fd;
	int		len = 4;

	fd = 1;
	buff = malloc(sizeof(char) * len + 1);
	if (!buff)
	{
		close(fd);
		return ;
	}
	read(fd, buff, len);
	// read(fd, buff, len);
	printf("%s", buff);
	free(buff);
	close(fd);
}