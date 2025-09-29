/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:10:24 by agarcia2          #+#    #+#             */
/*   Updated: 2025/09/29 15:17:51 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void	*s1, void *s2, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src;

	dst = (unsigned char *)s1;
	src = (unsigned char *)s2;
	if (src && dst == NULL)
		return (*dst);
	while (n-- > 0)
		*dst++ = *src++;
	return (*dst);
}
