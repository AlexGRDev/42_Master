/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:05:19 by agarcia2          #+#    #+#             */
/*   Updated: 2025/10/25 18:22:11 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	formats(va_list args, const char str)
{
	int	count;

	count = 0;
	if (str == 'c')
		count += ft_putchar(va_arg(args, int);
	va_end(args);
	return (count);

}
	int	ft_printf(const char *str, ...)
{
	int	count;
	va_list args;
	
	va_start(args str);
	count = 0;
	while(*str)
	{
		if (*str == '%')
		{
			count += formats(args, *str);
			count++;
		}
		else
			count += ft_putchar(*str);

		count++;
	}
	va_end(args);
	return (count);
}
