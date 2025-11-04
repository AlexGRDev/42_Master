/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 07:31:16 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/04 07:43:28 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	unsigned int	ptr;

	ptr = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ptr += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		ptr += ft_putnbr(n / 10);
		ptr += ft_putchar(n % 10 + '0');
	}
	else
		ptr += ft_putchar(n + '0');
	return (ptr);
}
