/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_costs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:59:48 by agarcia2          #+#    #+#             */
/*   Updated: 2026/02/08 13:06:28 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	abs_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	calc_rot_cost(int index, int len)
{
	int	mid;

	if (index < 0)
		return (0);
	mid = len / 2;
	if (index <= mid)
		return (index);
	return (index - len);
}

static int	calc_final_cost(int a, int b)
{
	int	abs_a;
	int	abs_b;

	abs_a = abs_val(a);
	abs_b = abs_val(b);
	if ((a >= 0 && b >= 0) || (a <= 0 && b <= 0))
	{
		if (abs_a > abs_b)
			return (abs_a);
		else
			return (abs_b);
	}
	return (abs_a + abs_b);
}

void	chunk_calc_costs(t_chunk *c, t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->len_b)
	{
		c->cost_a[i] = calc_rot_cost(c->target[i], s->len_a);
		c->cost_b[i] = calc_rot_cost(c->pos[i], s->len_b);
		c->cost[i] = calc_final_cost(c->cost_a[i], c->cost_b[i]);
		i++;
	}
}

int	find_cheapest(t_chunk *c, t_stack *s)
{
	int	i;
	int	best;
	int	id;

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
