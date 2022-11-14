#ifndef TESTS_H
# define TESTS_H

# include <stdio.h>
# include <fcntl.h>
# include "../../src/get_next_line.h"

void	run_test(const char *file_name, char *(f)(int));
void	test2(const char *file_name);

#endif