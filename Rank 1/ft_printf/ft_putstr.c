/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:46:03 by agarcia2          #+#    #+#             */
/*   Updated: 2026/07/20 14:12:12 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putstr(va_list *args)
{
	char	*str;

	str = (char *)va_arg(*args, char *);
	if (!str)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}
