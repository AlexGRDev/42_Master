/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:37:35 by agarcia2          #+#    #+#             */
/*   Updated: 2025/10/03 11:34:17 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	const char	*s;
	char		*d;
	size_t		len;

	s = src;
	d = dst;
	len = ft_strlen(src);
	if (dst_size)
	{
		while (*s && dst_size-- > 1)
			*d++ = *s++;
		*d = '\0';
	}
	return (len);
}
