/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 07:31:16 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/25 10:21:39 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	handle_int_min(void)
{
	int	written;

	written = write(1, "-2147483648", 11);
	if (written != 11)
		return (-1);
	return (11);
}

static int	put_positive(int n)
{
	int	ptr;
	int	written;

	ptr = 0;
	if (n > 9)
	{
		written = put_positive(n / 10);
		if (written == -1)
			return (-1);
		ptr += written;
	}
	written = ft_putchar(n % 10 + '0');
	if (written == -1)
		return (-1);
	ptr += written;
	return (ptr);
}

int	ft_putnbr(int n)
{
	int	written;
	int	count;

	if (n == -2147483648)
		return (handle_int_min());
	count = 0;
	if (n < 0)
	{
		written = ft_putchar('-');
		if (written == -1)
			return (-1);
		count += written;
		n *= -1;
	}
	written = put_positive(n);
	if (written == -1)
		return (-1);
	count += written;
	return (count);
}
