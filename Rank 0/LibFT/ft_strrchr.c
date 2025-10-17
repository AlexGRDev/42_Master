/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:45:23 by agarcia2          #+#    #+#             */
/*   Updated: 2025/10/03 19:41:45 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*str;
	unsigned char	chr;
	size_t			len;
	const char		*ocurrences;

	str = (char *)s;
	len = ft_strlen(str);
	chr = (unsigned char)c;
	if (chr == '\0')
		return ((char *)str + len);
	ocurrences = NULL;
	while (len--)
		if (*(str + len) == chr)
			return ((char *)str + len);
	if (*str == chr)
		ocurrences = str;
	return ((char *)ocurrences);
}
