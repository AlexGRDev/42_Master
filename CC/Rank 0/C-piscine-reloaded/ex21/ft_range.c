/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:21:48 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/10/10 16:23:35 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	nbr_range(int min, int max)
{
	return (max - min);
}

int	*ft_range(int min, int max)
{
	int	*arrays;
	int	nbr;
	int	i;

	if (min >= max)
	{
		arrays = NULL;
		return (arrays);
	}
	nbr = nbr_range(min, max);
	arrays = (int *)malloc(sizeof(int) * nbr);
	if (!arrays)
		return (NULL);
	i = 0;
	while (i < nbr)
	{
		arrays[i] = min;
		min++;
		i++;
	}
	return (arrays);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	int	*arrays;
	int	min;
	int	max;
	int	i;

	if(ac != 3)
		return (0);
	min = atoi(av[1]);
	max = atoi(av[2]);
	arrays = ft_range(min, max);
	i = 0;
	while(arrays[i])
	{
		printf("%d ", arrays[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/