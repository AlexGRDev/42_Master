/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:05:19 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/03 18:15:08 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	formats(va_list args, const char **str)
{
	if (**str == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (**str == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (**str == 'p')
		return (ft_printptr(va_arg(args, uintptr_t)));
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;	

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += formats(args, &str);
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (count);
}
