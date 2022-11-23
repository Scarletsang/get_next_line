#ifndef TESTS_H
# define TESTS_H

# include <stdio.h>
# include <fcntl.h>
# include "../../src/get_next_line.h"

typedef char *(*test_func)(int);

////////////////////////////////////////
//////////       input fd      /////////
////////////////////////////////////////

void	get_n_line_fd(test_func func, int fd, size_t n);

void	print_get_next_line(int fd);

////////////////////////////////////////
//////////   input file_name   /////////
////////////////////////////////////////

void	get_n_line(test_func func, const char *file_name, size_t n);

void	read_until_end(char *file_name);

////////////////////////////////////////
//////////        bonus        /////////
////////////////////////////////////////

void	bonus(char **argv);

#endif