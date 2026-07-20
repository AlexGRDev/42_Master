/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_num_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:18:30 by agarcia2          #+#    #+#             */
/*   Updated: 2026/07/20 15:18:31 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "test_runners.h"

void	run_int_case(int n, const char *fmt, const char *label, int *p)
{
	int	ft;
	int	og;

	printf("  ft: ");
	ft = ft_printf(fmt, n);
	printf("  og: ");
	og = printf(fmt, n);
	printf("\n");
	check(ft, og, label, p);
}

void	run_ptr_case(void *ptr, const char *label, int *passed)
{
	int	ft;
	int	og;

	printf("  ft: ");
	ft = ft_printf("[%p]", ptr);
	printf("  og: ");
	og = printf("[%p]", ptr);
	printf("\n");
	check(ft, og, label, passed);
}
