/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:18:34 by agarcia2          #+#    #+#             */
/*   Updated: 2025/09/24 18:22:10 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;
	int	size;

	if (min >= max)
		return (NULL);
	size = max - min;
	tab = (int *) malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < max)
	{
		tab[i] = min + 1;
		i++;
	}
	return (tab);
}
