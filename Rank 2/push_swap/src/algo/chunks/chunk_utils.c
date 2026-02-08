/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:59:03 by agarcia2          #+#    #+#             */
/*   Updated: 2026/02/08 13:02:21 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunk	*chunk_init(t_stack *s)
{
	int		len;
	t_chunk	*c;

	len = s->len_a;
	c = malloc(sizeof(t_chunk));
	if (!c)
		return (NULL);
	c->cheap = ft_calloc(len, sizeof(int));
	c->cost = ft_calloc(len, sizeof(int));
	c->cost_a = ft_calloc(len, sizeof(int));
	c->cost_b = ft_calloc(len, sizeof(int));
	c->move = ft_calloc(len, sizeof(int));
	c->pos = ft_calloc(len, sizeof(int));
	c->target = ft_calloc(len, sizeof(int));
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

static int	get_pos_after_max(t_stack *s)
{
	int	i;
	int	max;
	int	pos;

	max = s->a[0];
	pos = 0;
	i = 1;
	while (i < s->len_a)
	{
		if (s->a[i] > max)
		{
			max = s->a[i];
			pos = i;
		}
		i++;
	}
	return ((pos + 1) % s->len_a);
}

static int	find_target_in_a(t_stack *s, int val)
{
	int	i;
	int	best;
	int	pos;

	best = INT_MAX;
	pos = -1;
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
	if (pos != -1)
		return (pos);
	return (get_pos_after_max(s));
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
