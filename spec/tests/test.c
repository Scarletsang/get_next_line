/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:27:00 by htsang            #+#    #+#             */
/*   Updated: 2022/11/23 23:16:28 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

/////////////////////////////////////////
////////////     input fd     ///////////
/////////////////////////////////////////

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

void	print_get_next_line(int fd)
{
	char *str;
	
	str = get_next_line(fd);
	printf("return: [%s]", str);
	free(str);
}

////////////////////////////////////////
//////////   input file_name   /////////
////////////////////////////////////////

void	get_n_line(test_func func, const char *file_name, size_t n)
{
	int fd;

	fd = open(file_name,  O_RDONLY);
	get_n_line_fd(func, fd, n);
}

void	read_until_end(char *file_name)
{
	char	*str;
	int		fd;

	fd = open(file_name, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("[%s]", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}

//////////////////////////////////////////
////////////       bonus       ///////////
//////////////////////////////////////////

void	bonus(char **argv)
{
	int i;
	int	fd1 = open(argv[1],  O_RDONLY);
	int	fd2 = open(argv[2],  O_RDONLY);
	int	fd3 = open(argv[3],  O_RDONLY);

	while (i++ < 6)
	{
		print_get_next_line(fd1);
		print_get_next_line(fd2);
		print_get_next_line(fd3);
	}

	close(fd1);
	close(fd2);
	close(fd3);
}
