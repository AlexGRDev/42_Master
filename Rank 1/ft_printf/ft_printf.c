/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:30:48 by agarcia2          #+#    #+#             */
/*   Updated: 2026/07/20 13:09:46 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format(va_list *args, const char *str, t_fmt *formats)
{
	while (formats->fmt)
	{
		if (*(formats->fmt) == *str)
		{
			if (*str == 'c')
				return (formats->c(args));
			else if (*str == 's')
				return (formats->s(args));
		}
		formats++;
	}
	return (0);
}

static int	print_f(const char **fmt, va_list *args, t_fmt *formats)
{
	int	count;

	if (**fmt == '%' && *(fmt + 1))
	{
		(*fmt)++;
		count = format(args, *fmt, formats);
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
	t_fmt		formats[3];

	formats[0] = (t_fmt){"c", ft_putchar, NULL};
	formats[1] = (t_fmt){"s", NULL, ft_putstr};
	formats[2] = (t_fmt){NULL, NULL, NULL};
	va_start(args, fmt);
	ptr = fmt;
	count = 0;
	printed = 0;
	while (*ptr)
	{
		printed = print_f(&ptr, &args, formats);
		if (printed == -1)
		{
			va_end(args);
			return (-1);
		}
		count += printed;
	}
	va_end(args);
	return (count);
}
