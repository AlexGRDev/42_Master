/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:17:12 by agarcia2          #+#    #+#             */
/*   Updated: 2026/07/20 16:03:57 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

# include "./LibFT/libft.h"

typedef struct formtaers
{
	char	*fmt;
	int		(*f)(va_list *args);

}	t_fmt;

int	ft_printf(const char *fmt, ...);
int	ft_putchar(va_list *args);
int	ft_putstr(va_list *args);
int	ft_putnbr(va_list *args);
int	ft_putptr(va_list *args);
#endif
