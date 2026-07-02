/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 19:24:47 by agarcia2          #+#    #+#             */
/*   Updated: 2025/10/05 09:27:07 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*d;

	dup = malloc(ft_strlen(s1) + 1);
	if (!dup)
		return (NULL);
	d = dup;
	while (*s1)
		*d++ = *s1++;
	*d = '\0';
	return (dup);
}
