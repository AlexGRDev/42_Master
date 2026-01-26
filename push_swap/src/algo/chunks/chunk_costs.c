/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_costs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:59:48 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/26 11:16:24 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int abs_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void chunk_calc_costs(t_chunk *c, t_stack *s)
{
	int i;
	int a;
	int b;

	i = 0;
	while (i < s->len_b)
	{
		a = c->target[i];
		if (a <= s->len_a / 2)
			c->cost_a[i] = a;
		else
			c->cost_a[i] = a - s->len_a;

		b = c->pos[i];
		if (b <= s->len_b / 2)
			c->cost_b[i] = b;
		else
			c->cost_b[i] = b - s->len_b;

		if ((c->cost_a[i] > 0 && c->cost_b[i] > 0) || (c->cost_a[i] < 0 && c->cost_b[i] < 0))
		{
			if (abs_val(c->cost_a[i]) > abs_val(c->cost_b[i]))
				c->cost[i] = abs_val(c->cost_a[i]);
			else
				c->cost[i] = abs_val(c->cost_b[i]);
		}
		else
			c->cost[i] = abs_val(c->cost_a[i]) + abs_val(c->cost_b[i]);
		i++;
	}
}

int find_cheapest(t_chunk *c, t_stack *s)
{
	int i;
	int best;
	int id;

	i = 0;
	id = 0;
	best = INT_MAX;
	while (i < s->len_b)
	{
		if (c->cost[i] < best)
		{
			best = c->cost[i];
			id = i;
		}
		i++;
	}
	return (id);
}