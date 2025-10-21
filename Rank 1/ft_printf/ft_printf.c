/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:12:38 by agarcia2          #+#    #+#             */
/*   Updated: 2025/10/21 10:30:03 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	dispatch(char str, va_list ap)
{
	if (str == 'c')
		return (ft_putc((char)va_arg(ap, int)));
	else if (str == 's')
		return (ft_putstr((char *)va_arg(ap, char *)));
	if (str == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	ap;

	len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '\0')
				break ;
			len += dispatch(*str, ap);
		}
		else
			len += ft_putc(*str);
		str++;
	}
	va_end(ap);
	return (len);
}

int	main(void)
{
	int	len1;
	int	len2;

	printf("custom\n");
	len1 = ft_printf(" %c %c %c ", '0', 0, '1');
	printf("\n");
	printf("original\n");
	len2 = printf(" %c %c %c", '0', 0, '1');
	printf("\n");
	if (len1 == len2)
	{
		printf("custom %i\n", len1);
		printf("original %i\n", len2);
		return (write(1, "OK\n", 3));
	}
	else
		if (len1 != len2)
		{
			printf("custom %i\n", len1);
			printf("original %i\n", len2);
			return (write(1, "KO\n", 3));
		}
	return (0);
}
