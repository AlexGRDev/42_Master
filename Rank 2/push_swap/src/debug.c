/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:13:04 by agarcia2          #+#    #+#             */
/*   Updated: 2026/02/03 16:09:16 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	debug_print_stacks(t_stack *s, char *msg)
{
	int	i;

	ft_printf("\n=== DEBUG: %s ===\n", msg);
	ft_printf("A (%d): ", s->len_a);
	i = 0;
	while (i < s->len_a)
		ft_printf("%d ", s->a[i++]);
	ft_printf("\n");
	ft_printf("B (%d): ", s->len_b);
	i = 0;
	while (i < s->len_b)
		ft_printf("%d ", s->b[i++]);
	ft_printf("\n=====================\n");
}

int	debug_is_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->a)
	{
		if (s->a[i] > s->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	debug_check_sorted(t_stack *s)
{
	if (debug_is_sorted(s))
		ft_printf("DEBUG: A está ORDENADO ✔️\n");
	else
		ft_printf("DEBUG: A está DESORDENADO ❌\n");
}

void	debug_print_chunk(t_chunk *c, t_stack *s)
{
	int	i;

	ft_printf("\n=== DEBUG CHUNK INFO ===\n");
	ft_printf("idx |   B   | pos | target | cost_a | cost_b | final_cost\n");
	ft_printf("---------------------------------------------------------\n");
	i = 0;
	while (i < s->len_b)
	{
		printf("%3d | %5d | %3d | %6d | %6d | %6d | %10d\n",
			i,
			s->b[i],
			c->pos[i],
			c->target[i],
			c->cost_a[i],
			c->cost_b[i],
			c->cost[i]);
		i++;
	}
	ft_printf("=========================================================\n");
}

void	debug_print_cheapest(t_chunk *c, t_stack *s)
{
	int	id;
	int	idx;
	int	val;

	id = find_cheapest(c, s);
	idx = s->b[id];
	val = s->original[idx];
	printf("DEBUG: Cheapest index = %d (idx=%d, val=%d), cost = %d\n",
		id, idx, val, c->cost[id]);
}
