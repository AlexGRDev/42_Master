/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:03:17 by agarcia2          #+#    #+#             */
/*   Updated: 2025/10/22 10:52:53 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *str)
{
	const char	*ptr;

	ptr = str;
	if(!ptr)
		return (1);
	while (*ptr)
		ptr++;
	return (ptr - str);
}
