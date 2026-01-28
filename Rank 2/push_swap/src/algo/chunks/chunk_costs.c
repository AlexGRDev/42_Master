/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_costs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:59:48 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/28 14:50:52 by agarcia2         ###   ########.fr       */
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
	if (index <= len / 2)
		return (index);
	else
		return (index - len);
}

static int	calc_final_cost(int cost_a, int cost_b)
{
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		if (abs_val(cost_a) > abs_val(cost_b))
			return (abs_val(cost_a));
		else
			return (abs_val(cost_b));
	}
	else
		return (abs_val(cost_a) + abs_val(cost_b));
}

void	chunk_calc_costs(t_chunk *c, t_stack *s)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	while (i < s->len_b)
	{
		a = c->target[i];
		b = c->pos[i];
		c->cost_a[i] = calc_rot_cost(a, s->len_a);
		c->cost_b[i] = calc_rot_cost(b, s->len_b);
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
