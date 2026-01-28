/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_mid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 07:39:19 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/28 15:50:37 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_stack *s)
{
	int	i;
	int	pos;

	i = 1;
	pos = 0;
	while (i < s->len_a)
	{
		if (s->a[i] < s->a[pos])
			pos = i;
		i++;
	}
	return (pos);
}

static void	rotate_to_top(t_stack *s, int pos)
{
	if (pos <= s->len_a / 2)
	{
		while (pos-- > 0)
			ra(s);
	}
	else
	{
		while (pos++ < s->len_a)
			rra(s);
	}
}

static void	push_min(t_stack *s)
{
	int	pos;

	pos = find_min_pos(s);
	rotate_to_top(s, pos);
	pb(s);
}

void	sort_mid(t_stack *s)
{
	if (s->len_a <= 3)
	{
		if (s->len_a == 2)
			sort_2(s);
		else
			sort_3(s);
		return ;
	}
	while (s->len_a > 3)
		push_min(s);
	sort_3(s);
	while (s->len_b > 0)
		pa(s);
}
