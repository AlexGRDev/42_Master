/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:44:53 by agarcia2          #+#    #+#             */
/*   Updated: 2026/07/20 14:55:24 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putnbr(va_list *args)
{
	long	num;
	long	divisor;
	char	buf[13];
	int		idx;

	num = va_arg(*args, int);
	idx = 0;
	if (num < 0)
	{
		buf[idx++] = '-';
		num = -num;
	}
	divisor = 1;
	while (num / divisor >= 10)
		divisor *= 10;
	while (divisor > 0)
	{
		buf[idx++] = (num / divisor % 10) + '0';
		divisor /= 10;
	}
	buf[idx] = '\0';
	return (ft_strdup(buf));
}
