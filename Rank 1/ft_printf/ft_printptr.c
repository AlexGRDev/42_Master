/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:15:46 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/25 10:20:22 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static int	ft_put_ptr(uintptr_t num)
{
	int		high;
	int		low;

	if (num >= 16)
	{
		high = ft_put_ptr(num / 16);
		if (high == -1)
			return (-1);
		low = ft_put_ptr(num % 16);
		if (low == -1)
			return (-1);
		return (high + low);
	}
	if (num <= 9)
		high = ft_putchar(num + '0');
	else
		high = ft_putchar(num - 10 + 'a');
	if (high == -1)
		return (-1);
	return (1);
}

int	ft_printptr(uintptr_t ptr)
{
	int	length;
	int	written;

	length = write(1, "0x", 2);
	if (length != 2)
		return (-1);
	if (ptr == 0)
	{
		written = write(1, "0", 1);
		if (written != 1)
			return (-1);
		return (length + written);
	}
	written = ft_put_ptr(ptr);
	if (written == -1)
		return (-1);
	return (length + written);
}
