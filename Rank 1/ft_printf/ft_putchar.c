/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:00:00 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/25 10:21:03 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar(int c)
{
	size_t	written;

	written = write(1, &c, 1);
	if (written != 1)
		return (-1);
	return ((int)written);
}
