/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:10:24 by agarcia2          #+#    #+#             */
/*   Updated: 2025/09/29 23:19:27 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void	*s1, void *s2, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src;

	dst = (unsigned char *)s1;
	src = (unsigned char *)s2;
	while (n--)
	{
		if (*dst != *src)
			return ((int)*dst - (int)*src);
		dst++;
		src++;
	}
	return (0);
}
