/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 02:34:18 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/22 03:01:17 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void do_rotations(t_node **a, t_node **b, t_node *n)
{
	while (n->cost_a > 0 && n->cost_b > 0)
	{
		rr(a, b, 1);
		n->cost_a--;
		n->cost_b--;
	}
	while (n->cost_a < 0 && n->cost_b < 0)
	{
		rrr(a, b, 1);
		n->cost_a++;
		n->cost_b++;
	}

	while (n->cost_a > 0)
	{
		ra(a, 1);
		n->cost_a--;
	}
	while (n->cost_a < 0)
	{
		rra(a, 1);
		n->cost_a++;
	}

	while (n->cost_b > 0)
	{
		rb(b, 1);
		n->cost_b--;
	}
	while (n->cost_b < 0)
	{
		rrb(b, 1);
		n->cost_b++;
	}
}

void do_cheapest_move(t_node **a, t_node **b, t_node *best)
{
	do_rotations(a, b, best);
	pa(a, b, 1);
}

void sort_stacks(t_node **a, t_node **b)
{
	t_node *best;

	while (*b)
	{
		assign_target_positions(*a, *b);
		calculate_costs(*a, *b);
		best = get_cheapest_move(*b);
		do_cheapest_move(a, b, best);
	}

	update_positions(*a);

	t_node *tmp = *a;
	while (tmp && tmp->index != 0)
		tmp = tmp->next;
	if (!tmp)
		return;

	int size = stack_size(*a);
	if (tmp->pos <= size / 2)
		while ((*a)->index != 0)
			ra(a, 1);
	else
		while ((*a)->index != 0)
			rra(a, 1);
}