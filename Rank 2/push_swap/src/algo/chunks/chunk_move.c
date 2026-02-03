/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:00:19 by agarcia2          #+#    #+#             */
/*   Updated: 2026/02/03 00:34:56 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void chunk_do_cheapest_move(t_chunk *c, t_stack *s)
{
	int id;
	int a;
	int b;

	id = find_cheapest(c, s);
	a = c->cost_a[id];
	b = c->cost_b[id];
	while (a > 0 && b > 0)
		(rr(s), a--, b--);
	while (a < 0 && b < 0)
		(rrr(s), a++, b++);
	while (a > 0)
		(ra(s), a--);
	while (a < 0)
		(rra(s), a++);
	while (b > 0)
		(rb(s), b--);
	while (b < 0)
		(rrb(s), b++);
	pa(s);
}
