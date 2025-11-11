/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:16:48 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/11 15:29:12 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putu(unsigned int n)
{
	unsigned int	ptr;
	
	ptr = 0;
	if(n > 9)
	{
		ptr += ft_putchar(n / 10);
		ptr += ft_putchar(n % 10 + '0');
	}
	else
		ptr = ft_putchar(n + '0');
	return (ptr);
}
