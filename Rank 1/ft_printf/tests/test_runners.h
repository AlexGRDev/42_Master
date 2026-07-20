/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_runners.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:18:48 by agarcia2          #+#    #+#             */
/*   Updated: 2026/07/20 15:18:50 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_RUNNERS_H
# define TEST_RUNNERS_H

void	check(int ft, int og, const char *label, int *passed);
void	run_char_case(char c, const char *fmt, const char *label, int *passed);
void	run_str_case(char *s, const char *fmt, const char *label, int *passed);
void	run_int_case(int n, const char *fmt, const char *label, int *p);
void	run_ptr_case(void *ptr, const char *fmt, const char *label, int *p);
int		run_all_tests(void);

#endif
