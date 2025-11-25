/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:34:36 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/25 10:20:03 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned int nr, const char *base)
{
	int	nr_base[16];
	int	i;
	int	result;
	int	written;

	i = 0;
	result = 0;
	if (nr == 0)
		return (ft_putchar('0'));
	while (nr)
	{
		nr_base[i] = nr % 16;
		nr /= 16;
		i++;
	}
	while (--i >= 0)
	{
		written = ft_putchar(base[nr_base[i]]);
		if (written == -1)
			return (-1);
		result += written;
	}
	return (result);
}
