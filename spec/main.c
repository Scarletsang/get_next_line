/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:52:46 by htsang            #+#    #+#             */
/*   Updated: 2022/11/20 18:20:00 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"

int	main(int argc, char **argv)
{
	// return (printf("%zd\n", read(1, NULL, 3)));
	get_n_line(&get_next_line, argv[1], atoi(argv[2]));
	// test2(argv[1]);
	return (0);
}