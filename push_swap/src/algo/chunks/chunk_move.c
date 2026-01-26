/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:00:19 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/26 10:45:09 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rotate_a(t_stack *s, int *n)
{
	while (*n > 0)
	{
		ra(s);
		(*n)--;
	}
	while (*n < 0)
	{
		rra(s);
		(*n)++;
	}
}

static void	do_rotate_b(t_stack *s, int *n)
{
	while (*n > 0)
	{
		rb(s);
		(*n)--;
	}
	while (*n < 0)
	{
		rrb(s);
		(*n)++;
	}
}

void	chunk_do_cheapest_move(t_chunk *c, t_stack *s)
{
	int	id;

	id = find_cheapest(c, s);
	while (c->cost_a[id] > 0 && c->cost_b[id] > 0)
	{
		rr(s);
		c->cost_a[id]--;
		c->cost_b[id]--;
	}
	while (c->cost_a[id] < 0 && c->cost_b[id] < 0)
	{
		rrr(s);
		c->cost_a[id]++;
		c->cost_b[id]++;
	}
	do_rotate_a(s, &c->cost_a[id]);
	do_rotate_b(s, &c->cost_b[id]);
	pa(s);
}
