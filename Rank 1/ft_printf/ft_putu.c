/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:16:48 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/17 12:46:33 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

int	ft_putu(unsigned int n)
{
	int	ptr;

	ptr = 0;
	if (n > 9)
		ptr += ft_putu(n / 10);
	ptr += ft_putchar((n % 10) + '0');
	return (ptr);
}
