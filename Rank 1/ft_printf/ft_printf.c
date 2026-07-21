/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:30:48 by agarcia2          #+#    #+#             */
/*   Updated: 2026/07/20 16:09:57 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

static int	format(va_list *args, const char *str, t_fmt ***formats)
{
	t_fmt	*f;

	f = **formats;
	while (f && f->fmt)
	{
		if (*(f->fmt) == *str)
			return (f->f(args));
		f++;
	}
	return (0);
}

static int	print_f(const char **fmt, va_list *args, t_fmt **formats)
{
	int	count;

	if (**fmt == '%' && *(*fmt + 1))
	{
		(*fmt)++;
		count = format(args, *fmt, &formats);
		(*fmt)++;
		return (count);
	}
	count = write(1, *fmt, 1);
	(*fmt)++;
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	int			count;
	int			printed;
	const char	*ptr;
	t_fmt		*formats;

	formats = malloc(sizeof(t_fmt) * 6);
	formats[0] = (t_fmt){"c", ft_putchar};
	formats[1] = (t_fmt){"s", ft_putstr};
	formats[2] = (t_fmt){"i", ft_putnbr};
	formats[3] = (t_fmt){"d", ft_putnbr};
	formats[4] = (t_fmt){"p", ft_putptr};
	formats[5] = (t_fmt){NULL, NULL};
	va_start(args, fmt);
	ptr = fmt;
	count = 0;
	while (*ptr)
	{
		printed = print_f(&ptr, &args, &formats);
		if (printed == -1)
			return (va_end(args), -1);
		count += printed;
	}
	va_end(args);
	return (count);
}
