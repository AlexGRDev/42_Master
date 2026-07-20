/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_suite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:19:18 by agarcia2          #+#    #+#             */
/*   Updated: 2026/07/20 15:19:23 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "test_runners.h"
#include <limits.h>

static void	run_numeric_group(int *passed)
{
	int	sample_value;

	sample_value = 42;
	run_int_case(0, "[%d]", "%d cero", passed);
	run_int_case(-1, "[%d]", "%d negativo", passed);
	run_int_case(42, "[%d]", "%d positivo", passed);
	run_int_case(INT_MAX, "[%d]", "%d INT_MAX", passed);
	run_int_case(INT_MIN, "[%d]", "%d INT_MIN", passed);
	run_int_case(123, "[%i]", "%i positivo", passed);
	run_int_case(-123, "[%i]", "%i negativo", passed);
	run_ptr_case(&sample_value, "[%p]", "%p direccion", passed);
	run_ptr_case(NULL, "[%p]", "%p NULL", passed);
	run_int_case(42, "[%u]", "%u positivo", passed);
	run_int_case(255, "[%x]", "%x minuscula", passed);
	run_int_case(255, "[%X]", "%X mayuscula", passed);
}

static void	run_bonus_group(int *passed)
{
	run_int_case(42, "[%5d]", "%5d width", passed);
	run_int_case(42, "[%-5d]", "%-5d left", passed);
	run_int_case(42, "[%05d]", "%05d zero", passed);
	run_int_case(-42, "[%05d]", "%05d neg zero", passed);
	run_int_case(255, "[%08X]", "%08X zero", passed);
	run_int_case(255, "[%08p]", "%08p zero", passed);
	run_str_case("hi", "[%10s]", "%10s width", passed);
	run_str_case("hi", "[%-10s]", "%-10s left", passed);
	run_str_case("hello", "[%.3s]", "%.3s prec", passed);
	run_char_case('A', "[%5c]", "%5c width", passed);
	run_char_case('A', "[%-5c]", "%-5c left", passed);
}

int	run_all_tests(void)
{
	int	passed_count;

	passed_count = 0;
	printf("=== ft_printf: edge cases + bonus flags ===\n\n");
	run_char_case('A', "[%c]", "%c letra", &passed_count);
	run_char_case('0', "[%c]", "%c digito", &passed_count);
	run_char_case(' ', "[%c]", "%c espacio", &passed_count);
	run_char_case('\n', "[%c]", "%c newline", &passed_count);
	run_char_case(0, "[%c]", "%c byte nulo", &passed_count);
	run_str_case("Hola mundo", "[%s]", "%s normal", &passed_count);
	run_str_case("", "[%s]", "%s vacio", &passed_count);
	run_str_case(NULL, "[%s]", "%s NULL", &passed_count);
	run_str_case("x", "[%s]", "%s un char", &passed_count);
	run_numeric_group(&passed_count);
	run_bonus_group(&passed_count);
	return (passed_count);
}
