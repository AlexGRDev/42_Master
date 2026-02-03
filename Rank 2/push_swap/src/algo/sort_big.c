/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 00:03:39 by agarcia2          #+#    #+#             */
/*   Updated: 2026/02/03 15:59:22 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks_to_b(t_stack *s)
{
	int	chunk;
	int	count;

	chunk = get_chunk_size(s->len_a);
	count = 0;
	while (s->len_a > 3)
	{
		if (count == chunk)
			count = 0;
		pb(s);
		count++;
	}
}

static int	find_min_position(t_stack *s)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (i < s->len_a)
	{
		if (s->a[i] < s->a[pos])
			pos = i;
		i++;
	}
	return (pos);
}

static void	final_rotate(t_stack *s)
{
	int	pos;

	pos = find_min_position(s);
	if (pos <= s->len_a / 2)
		while (pos--)
			ra(s);
	else
		while (pos++ < s->len_a)
			rrr(s);
}

void	sort_big(t_stack *s)
{
	t_chunk	*c;

	c = chunk_init(s);
	if (!c)
		return ;
	push_chunks_to_b(s);
	sort_3(s);
	while (s->len_b > 0)
	{
		chunk_calc_positions(c, s);
		chunk_calc_target(c, s);
		chunk_calc_costs(c, s);
		chunk_do_cheapest_move(c, s);
	}
	final_rotate(s);
	free_chunks(c);
}
