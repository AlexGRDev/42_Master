/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:30:48 by agarcia2          #+#    #+#             */
/*   Updated: 2026/07/20 17:40:00 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	calc_len(char *raw, t_mods *mods, char conv)
{
	mods->len = ft_strlen(raw);
	if (conv == 'c')
		mods->len = 1;
	else if (mods->prec >= 0 && conv == 's' && mods->prec < mods->len)
		mods->len = mods->prec;
	mods->padc = ' ';
	if (mods->zero && !mods->minus && ft_strchr("diuxX", conv))
		mods->padc = '0';
	if (mods->zero && !mods->minus && conv == 'p' && *raw == '0')
		mods->padc = '0';
}

static int	pad_write(char *raw, t_mods *mods, char conv)
{
	int	pad_count;
	int	count;

	calc_len(raw, mods, conv);
	pad_count = mods->width - mods->len;
	count = 0;
	if (mods->padc == '0' && *raw == '-')
	{
		count += write(1, raw++, 1);
		mods->len--;
	}
	else if (mods->padc == '0' && conv == 'p' && raw[0] == '0')
	{
		count += write(1, raw, 2);
		raw += 2;
		mods->len -= 2;
	}
	if (!mods->minus)
		while (pad_count-- > 0)
			count += write(1, &mods->padc, 1);
	count += write(1, raw, mods->len);
	while (mods->minus && pad_count-- > 0)
		count += write(1, " ", 1);
	return (count);
}

static int	print_f(const char **fmt, va_list *args, t_fmt **formats)
{
	t_mods	mods;
	t_fmt	*entry;
	char	*raw;
	char	conv;
	int		count;

	if (**fmt != '%' || !*(*fmt + 1))
		return (write(1, (*fmt)++, 1));
	(*fmt)++;
	parse_mods(fmt, &mods);
	conv = **fmt;
	raw = NULL;
	entry = *formats;
	while (entry && entry->fmt)
	{
		if (*(entry->fmt) == conv)
			raw = entry->conv_fn(args);
		entry++;
	}
	(*fmt)++;
	if (!raw)
		return (0);
	count = pad_write(raw, &mods, conv);
	return (free(raw), count);
}

void	init_formats(t_fmt *formats)
{
	formats[0] = (t_fmt){"c", ft_putchar};
	formats[1] = (t_fmt){"s", ft_putstr};
	formats[2] = (t_fmt){"i", ft_putnbr};
	formats[3] = (t_fmt){"d", ft_putnbr};
	formats[4] = (t_fmt){"p", ft_putptr};
	formats[5] = (t_fmt){"u", ft_putund};
	formats[6] = (t_fmt){"x", ft_puthex};
	formats[7] = (t_fmt){"X", ft_puthexmaj};
	formats[8] = (t_fmt){NULL, NULL};
}

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	int			total_count;
	int			printed_count;
	const char	*cursor;
	t_fmt		*formats;

	formats = malloc(sizeof(t_fmt) * 9);
	init_formats(formats);
	va_start(args, fmt);
	cursor = fmt;
	total_count = 0;
	while (*cursor)
	{
		printed_count = print_f(&cursor, &args, &formats);
		if (printed_count == -1)
			return (free(formats), va_end(args), -1);
		total_count += printed_count;
	}
	return (free(formats), va_end(args), total_count);
}
