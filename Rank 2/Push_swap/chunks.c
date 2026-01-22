/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 03:06:32 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/22 03:06:42 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_all_to_b(t_node **a, t_node **b)
{
	int size = stack_size(*a);
	int chunk_count = (size <= 100) ? 5 : 11;
	int chunk_size = size / chunk_count;
	int limit = chunk_size;
	int pushed = 0;

	while (*a)
	{
		if ((*a)->index < limit)
		{
			pb(a, b, 1);
			pushed++;
			if ((*b)->index < limit - (chunk_size / 2))
				rb(b, 1);
			if (pushed == limit)
				limit += chunk_size;
		}
		else
			ra(a, 1);
	}
}