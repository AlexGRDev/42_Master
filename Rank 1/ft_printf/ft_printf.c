/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:33:50 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/17 13:34:00 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "LibFT/libft.h"

static int	formats(va_list *args, const char **str)
{
	if (**str == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (**str == 'd' || **str == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (**str == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (**str == 'p')
		return (ft_printptr(va_arg(*args, uintptr_t)));
	else if (**str == 'u')
		return (ft_putu(va_arg(*args, unsigned int)));
	else if (**str == 'x')
		return (ft_printhex(va_arg(*args, unsigned int), "0123456789abcdef"));
	else if (**str == 'X')
		return (ft_printhex(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	else if (**str == '%')
		return (ft_putchar('%'));
	return (0);
}

static int	print_current(const char **ptr, va_list *args)
{
	if (**ptr == '%')
	{
		(*ptr)++;
		return (formats(args, ptr));
	}
	return (ft_putchar(**ptr));
}

int	ft_printf(const char *str, ...)
{
	int			count;
	int			printed;
	va_list		args;
	const char	*ptr;

	if (!str)
		return (write(1, "(null)", 6));
	va_start(args, str);
	count = 0;
	ptr = str;
	while (*ptr)
	{
		printed = print_current(&ptr, &args);
		if (printed == -1)
		{
			va_end(args);
			return (-1);
		}
		count += printed;
		ptr++;
	}
	va_end(args);
	return (count);
}
