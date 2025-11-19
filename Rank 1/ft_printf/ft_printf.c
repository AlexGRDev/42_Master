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

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	str = (char *)malloc(sizeof(*str * (ft_strlen((const char *)str) + 1)));
	if (!str)
		write(1, "(null)", 6);
	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += formats(&args, &str);
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(args);
	free((void *)str);
	str = NULL;
	return (count);
}
