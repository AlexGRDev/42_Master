/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:35:00 by agarcia2          #+#    #+#             */
/*   Updated: 2026/07/20 16:35:00 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_puthex(va_list *args)
{
	unsigned int	num;
	unsigned int	divisor;
	char			buf[9];
	int				idx;

	num = va_arg(*args, unsigned int);
	idx = 0;
	divisor = 1;
	while (num / divisor >= 16)
		divisor *= 16;
	while (divisor > 0)
	{
		buf[idx++] = "0123456789abcdef"[(num / divisor) % 16];
		divisor /= 16;
	}
	buf[idx] = '\0';
	return (ft_strdup(buf));
}
