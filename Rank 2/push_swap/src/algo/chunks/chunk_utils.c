/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:59:03 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/26 11:20:08 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunk *chunk_init(t_stack *s)
{
	t_chunk *c;
	int		len;

	len = s->len_a;
	c = malloc(sizeof(t_chunk));
	if (!c)
		return (NULL);
	c->cheap = malloc(sizeof(int) * len);
	c->cost = malloc(sizeof(int) * len);
	c->cost_a = malloc(sizeof(int) * len);
	c->cost_b = malloc(sizeof(int) * len);
	c->move = malloc(sizeof(int) * len);
	c->pos = malloc(sizeof(int) * len);
	c->target = malloc(sizeof(int) * len);
	if (!c->cheap || !c->cost || !c->cost_a || !c->cost_b
		|| !c->move || !c->pos || !c->target)
		return (NULL);
	return (c);
}

void	chunk_calc_positions(t_chunk *c, t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->len_b)
	{
		c->pos[i] = i;
		i++;
	}
}

static int	find_min_pos(t_stack *s)
{
	int	i;
	int	pos;

	pos = 0;
	i = 1;
	while (i < s->len_a)
	{
		if (s->a[i] < s->a[pos])
			pos = i;
		i++;
	}
	return (pos);
}

static int	find_target_in_a(t_stack *s, int val)
{
	int	i;
	int	best;
	int	pos;

	best = INT_MAX;
	pos = find_min_pos(s);
	i = 0;
	while (i < s->len_a)
	{
		if (s->a[i] > val && s->a[i] < best)
		{
			best = s->a[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

void	chunk_calc_target(t_chunk *c, t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->len_b)
	{
		c->target[i] = find_target_in_a(s, s->b[i]);
		i++;
	}
}
