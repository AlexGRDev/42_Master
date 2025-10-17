/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:11:46 by agarcia2          #+#    #+#             */
/*   Updated: 2025/10/04 12:26:57 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*b;
	const char	*l;
	size_t		count;

	if (!*little)
		return ((char *)big);
	while (*big && len > 0)
	{
		b = big;
		l = little;
		count = len;
		while (*l && *b == *l && count > 0)
		{
			b++;
			l++;
			count--;
		}
		if (!*l)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
