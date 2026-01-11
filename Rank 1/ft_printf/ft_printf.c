/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexgarcia2 <agarcia2@student.42barcelo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 21:08:58 by alexgarcia2       #+#    #+#             */
/*   Updated: 2026/01/11 22:19:47 by alexgarcia2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char *format, va_list *ap)
{
	if (*format == '\0')
		return (-1);
	else if (*format == 'c')
		return (ft_printf_c(va_arg(*ap, int)));
	else if (*format == 's')
		return (ft_printf_s(va_arg(*ap, char *)));
	else if (*format == 'd' || *format == 'i')
		return (ft_printf_d(va_arg(*ap, int)));
	else if (*format == 'u')
		return (ft_printf_u(va_arg(*ap, unsigned int)));
	else if (*format == 'x')
		return (ft_printf_x(va_arg(*ap, unsigned int), 0));
	else if (*format == 'X')
		return (ft_printf_x(va_arg(*ap, unsigned int), 1));
	else if (*format == 'p')
		return (ft_printf_p(va_arg(*ap, void *)));
	else
		return (ft_printf_c('%'));
}

int	ft_printf(char const *format, ...)
{
	int		len;
	int		to_fomat;
	va_list	ap;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			to_fomat = ft_format(format, &ap);
			if (to_fomat < 0)
				return (to_fomat);
			len += to_fomat;
		}
		else
			len += ft_printf_c(*format);
		format++;
	}
	va_end(ap);
	return (len);
}
