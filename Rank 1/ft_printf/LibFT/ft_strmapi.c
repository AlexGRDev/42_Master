/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:07:06 by agarcia2          #+#    #+#             */
/*   Updated: 2026/03/24 10:08:46 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*res;
	char				*ptr;

	if (!s || !f)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (NULL);
	ptr = res;
	i = 0;
	while (*s)
		*ptr++ = f(i++, *s++);
	*ptr = '\0';
	return (res);
}
