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

int	ft_putnbr(va_list *args)
{
	long	n;
	long	div;
	int		count;
	char	c;

	n = va_arg(*args, int);
	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	div = 1;
	while (n / div >= 10)
		div *= 10;
	while (div > 0)
	{
		c = (n / div % 10) + '0';
		count += write(1, &c, 1);
		div /= 10;
	}
	return (count);
}
