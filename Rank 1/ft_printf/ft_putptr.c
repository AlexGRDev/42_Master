/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:20:00 by agarcia2          #+#    #+#             */
/*   Updated: 2026/07/20 15:20:00 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(va_list *args)
{
	uintptr_t	addr;
	uintptr_t	div;
	int			count;
	char		c;

	addr = (uintptr_t)va_arg(*args, void *);
	if (!addr)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	div = 1;
	while (addr / div >= 16)
		div *= 16;
	while (div > 0)
	{
		c = "0123456789abcdef"[(addr / div) % 16];
		count += write(1, &c, 1);
		div /= 16;
	}
	return (count);
}
