/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:26:29 by agarcia2          #+#    #+#             */
/*   Updated: 2025/09/28 08:44:36 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst,
		const void *restrict src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	unsigned char	chr;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	chr = (unsigned char)c;
	while (n > 0)
	{
		if (*s == c)
			return ((void *)(d + 1));
		*d++ = *s++;
	}
	return (NULL);
}
