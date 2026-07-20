/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:46:03 by agarcia2          #+#    #+#             */
/*   Updated: 2026/07/20 12:59:05 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_putstr(va_list *args)
{
	char	*s;
	int		len;

	s = (char *)va_arg(*args, char *);
	len = ft_strlen(s);
	while (*s)
		write(1, s++, 1);
	return (len);
}
