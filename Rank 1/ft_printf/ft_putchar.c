/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:24:07 by agarcia2          #+#    #+#             */
/*   Updated: 2026/07/20 12:24:24 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putchar(va_list *args)
{
	char	*buf;

	buf = malloc(2);
	if (!buf)
		return (NULL);
	buf[0] = (char)va_arg(*args, int);
	buf[1] = '\0';
	return (buf);
}
