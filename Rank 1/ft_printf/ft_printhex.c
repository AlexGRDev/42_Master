/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:34:36 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/17 13:34:40 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LibFT/libft.h"
#include "ft_printf.h"

int	ft_printhex(unsigned int nr, char *base)
{
	int	nr_base[16];
	int	i;
	int	result;

	base = (char *)malloc(sizeof(*base * ft_strlen(base) + 1));
	i = 0;
	result = 0;
	if (nr == 0)
		result += ft_putchar('0');
	while (nr)
	{
		nr_base[i] = nr % 16;
		nr = nr / 16;
		i++;
	}
	while (--i >= 0)
		result += ft_putchar(base[nr_base[i]]);
	free(base);
	base = NULL;
	return (result);
}
