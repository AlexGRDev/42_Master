/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putund.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:35:00 by agarcia2          #+#    #+#             */
/*   Updated: 2026/07/20 16:35:00 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putund(va_list *args)
{
	unsigned int	num;
	unsigned int	divisor;
	char			buf[11];
	int				idx;

	num = va_arg(*args, unsigned int);
	idx = 0;
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
