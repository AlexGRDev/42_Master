/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:29:04 by agarcia2          #+#    #+#             */
/*   Updated: 2025/09/27 00:34:00 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, char *src, size_t size)
{
	int	len;
	int	i;

	len = ft_strlen(src);
	if (size > 0)
	{
		while (*src && i < size - 1)
		{
			*(dst)++ = *(src)++;
			i++;
		}
		*dst = '\0';
	}
	return (len);
}
