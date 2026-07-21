/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:28:00 by agarcia2          #+#    #+#             */
/*   Updated: 2026/07/20 15:30:00 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "tests/test_runners.h"

#define TOTAL_TESTS 18

int	main(void)
{
	int	passed;

	setbuf(stdout, NULL);
	passed = run_all_tests();
	printf("\n%d/%d tests OK\n", passed, TOTAL_TESTS);
	if (passed != TOTAL_TESTS)
		return (1);
	return (0);
}
