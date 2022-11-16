#ifndef TESTS_H
# define TESTS_H

# include <stdio.h>
# include <fcntl.h>
# include "../../src/get_next_line.h"

typedef char *(*test_func)(int);

void	get_n_line_fd(test_func func, int fd, size_t n);

void	get_n_line(test_func func, const char *file_name, size_t n);

#endif