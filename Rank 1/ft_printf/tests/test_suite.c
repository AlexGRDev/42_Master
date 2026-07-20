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

int	run_all_tests(void)
{
	int	passed;
	int	x;

	passed = 0;
	x = 42;
	printf("=== ft_printf: edge cases %%c/%%s/%%d/%%i/%%p ===\n\n");
	run_char_case('A', "%c letra", &passed);
	run_char_case('0', "%c digito", &passed);
	run_char_case(' ', "%c espacio", &passed);
	run_char_case('\n', "%c newline", &passed);
	run_char_case(0, "%c byte nulo", &passed);
	run_str_case("Hola mundo", "%s normal", &passed);
	run_str_case("", "%s vacio", &passed);
	run_str_case(NULL, "%s NULL", &passed);
	run_str_case("x", "%s un char", &passed);
	run_int_case(0, "[%d]", "%d cero", &passed);
	run_int_case(-1, "[%d]", "%d negativo", &passed);
	run_int_case(42, "[%d]", "%d positivo", &passed);
	run_int_case(INT_MAX, "[%d]", "%d INT_MAX", &passed);
	run_int_case(INT_MIN, "[%d]", "%d INT_MIN", &passed);
	run_int_case(123, "[%i]", "%i positivo", &passed);
	run_int_case(-123, "[%i]", "%i negativo", &passed);
	run_ptr_case(&x, "%p direccion", &passed);
	run_ptr_case(NULL, "%p NULL", &passed);
	return (passed);
}
