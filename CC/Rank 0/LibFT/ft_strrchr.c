/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 07:32:16 by agarcia2          #+#    #+#             */
/*   Updated: 2025/09/28 09:14:05 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	chr;
	char			*last;

	if (!s)
		return (NULL);
	chr = (unsigned char)c;
	last = NULL;
	while (*s)
	{
		if (*s == chr)
			*last = *s;
		s++;
	}
	if (*s == chr)
		return ((char *)s);
	return ((char *)last);
}
