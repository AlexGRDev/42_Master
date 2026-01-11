/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexgarcia2 <agarcia2@student.42barcelo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 21:25:09 by alexgarcia2       #+#    #+#             */
/*   Updated: 2026/01/11 21:25:14 by alexgarcia2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c(char c)
{
	return (write(1, &c, 1));
}

int	ft_printf_s(char *s)
{
	int	count;

	if (!s)
		return (ft_printf_s("(null)"));
	count = 0;
	while (*s)
		count += ft_printf_c(*s++);
	return (count);
}

int	ft_printf_d(int d)
{
	int		count;
	long	l;
	char	c;

	l = d;
	count = 0;
	if (l < 0)
	{
		count += ft_printf_c('-');
		l = -l;
	}
	if (l > 9)
		count += ft_printf_d(l / 10);
	c = (l % 10) + '0';
	count += ft_printf_c(c);
	return (count);
}

int	ft_printf_u(unsigned int u)
{
	int		count;
	char	c;

	count = 0;
	if (u > 9)
		count += ft_printf_u(u / 10);
	c = (u % 10) + '0';
	count += ft_printf_c(c);
	return (count);
}