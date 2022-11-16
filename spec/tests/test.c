/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:27:00 by htsang            #+#    #+#             */
/*   Updated: 2022/11/16 13:43:11 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	run_test(const char *file_name, char *(f)(int))
{
	char	*str;
	int		fd;

	fd = open(file_name,  O_RDONLY);
	str = f(fd);
	printf("[Returns: %s]\n", str);
	free(str);
	str = f(fd);
	printf("[Returns: %s]\n", str);
	free(str);
	str = f(fd);
	printf("[Returns: %s]\n", str);
	free(str);
	str = f(fd);
	printf("[Returns: %s]\n", str);
	free(str);
	str = f(fd);
	printf("[Returns: %s]\n", str);
	free(str);
	close(fd);
	fd = open(file_name,  O_RDONLY);
	str = f(fd);
	printf("[Returns: %s]\n", str);
	free(str);
	str = f(fd);
	printf("[Returns: %s]\n", str);
	free(str);
	str = f(fd);
	printf("[Returns: %s]\n", str);
	free(str);
	str = f(fd);
	printf("[Returns: %s]\n", str);
	free(str);
	str = f(fd);
	printf("[Returns: %s]\n", str);
	free(str);
	close(fd);

}

void	test2(const char *file_name)
{
	int		fd;
	int		len = 4;
	char	buff[len + 1];

	fd = 1;
	if (!read(fd, buff, len))
	{
		printf("shit");
	}
	else
	{
		printf("%s", (char *) buff);	
	}
	if (!read(fd, buff, len))
	{
		printf("shit");
	}
	else
	{
		printf("%s", (char *) buff);	
	}
	close(fd);
}