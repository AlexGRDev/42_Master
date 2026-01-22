/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 03:06:54 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/22 03:06:55 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int calc_rot(int pos, int size)
{
	if (pos <= size / 2)
		return pos;
	return pos - size;
}

void calculate_costs(t_node *a, t_node *b)
{
	int size_a = stack_size(a);
	int size_b = stack_size(b);

	while (b)
	{
		b->cost_b = calc_rot(b->pos, size_b);
		b->cost_a = calc_rot(b->target_pos, size_a);
		b = b->next;
	}
}

t_node *get_cheapest_move(t_node *b)
{
	long best = __LONG_MAX__;
	long cost;
	t_node *tmp = b;
	t_node *best_node = b;

	while (tmp)
	{
		cost = llabs(tmp->cost_a) + llabs(tmp->cost_b);
		if (cost < best)
		{
			best = cost;
			best_node = tmp;
		}
		tmp = tmp->next;
	}
	return best_node;
}