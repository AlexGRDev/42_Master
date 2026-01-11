/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexgarcia2 <agarcia2@student.42barcelo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 21:16:23 by alexgarcia2       #+#    #+#             */
/*   Updated: 2026/01/11 22:18:28 by alexgarcia2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_format(const char *format, va_list *ap);
int	ft_printf(const char *format, ...);
int	ft_printf_c(char c);
int	ft_printf_s(char *s);
int	ft_printf_d(int d);
int	ft_printf_u(unsigned int u);
int	ft_printf_x(unsigned long x, int up);
int	ft_printf_p(void *p);
#endif
