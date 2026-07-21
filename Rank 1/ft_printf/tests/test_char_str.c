/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_char_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:18:01 by agarcia2          #+#    #+#             */
/*   Updated: 2026/07/20 15:18:06 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "test_runners.h"

void	check(int ft, int og, const char *label, int *passed)
{
	if (ft == og)
	{
		(*passed)++;
		printf("  \033[32mOK\033[0m  %-14s ft=%-3d og=%-3d\n", label, ft, og);
	}
	else
		printf("  \033[31mKO\033[0m  %-14s ft=%-3d og=%-3d\n", label, ft, og);
}

void	run_char_case(char c, const char *label, int *passed)
{
	int	ft;
	int	og;

	printf("  ft: ");
	ft = ft_printf("[%c]", c);
	printf("  og: ");
	og = printf("[%c]", c);
	printf("\n");
	check(ft, og, label, passed);
}

void	run_str_case(char *s, const char *label, int *passed)
{
	int	ft;
	int	og;

	printf("  ft: ");
	ft = ft_printf("[%s]", s);
	printf("  og: ");
	og = printf("[%s]", s);
	printf("\n");
	check(ft, og, label, passed);
}
