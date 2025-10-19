/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:02:53 by agarcia2          #+#    #+#             */
/*   Updated: 2025/10/19 20:50:26 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "LibFT/libft.h"

int	ft_printf(const char *format, ...);
int	ft_formats(va_list args, const char format);
int	ft_putchar_pf(char c);
int	ft_putstr_pf(char *s);
int	ft_putnbr_pf(int n);
int	ft_put_unsigned_pf(unsigned int n);
int	ft_puthex_pf(unsigned int n, const char format);
int	ft_putptr_pf(unsigned long long ptr);

#endif
