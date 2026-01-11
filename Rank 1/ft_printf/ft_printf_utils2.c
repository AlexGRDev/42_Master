/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexgarcia2 <agarcia2@student.42barcelo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 21:26:01 by alexgarcia2       #+#    #+#             */
/*   Updated: 2026/01/11 21:26:09 by alexgarcia2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_x(unsigned long x, int up)
{
	char	*base;
	char	c;
	int		count;

	base = "0123456789abcdef";
	if (up)
		base = "0123456789ABCDEF";
	count = 0;
	if (x >= 16)
		count += ft_printf_x(x / 16, up);
	c = base[x % 16];
	count += ft_printf_c(c);
	return (count);
}

int	ft_printf_p(void *p)
{
	int		count;

	count = 0;
	if (!p)
		return (ft_printf_s("(nil)"));
	count += ft_printf_s("0x");
	count += ft_printf_x((size_t)p, 0);
	return (count);
}