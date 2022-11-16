/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:52:46 by htsang            #+#    #+#             */
/*   Updated: 2022/11/16 14:38:33 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"

int	main(int argc, char **argv)
{
	get_n_line(&get_next_line, "inputs/1char.txt", 6);
	get_n_line(&get_next_line, "inputs/input.txt", 6);
	// test2(argv[1]);
	return (0);
}