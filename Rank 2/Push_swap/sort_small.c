/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 02:26:58 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/22 02:49:37 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_2(t_node **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}

void sort_3(t_node **a)
{
	int x = (*a)->value;
	int y = (*a)->next->value;
	int z = (*a)->next->next->value;

	if (x > y && x < z)
		sa(a, 1);
	else if (x > y && y > z)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (x > z && y < z)
		ra(a, 1);
	else if (x < y && x > z)
		rra(a, 1);
	else if (x < y && y > z)
	{
		sa(a, 1);
		ra(a, 1);
	}
}

void sort_5(t_node **a, t_node **b)
{
	while (stack_size(*a) > 3)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
			pb(a, b, 1);
		else
			ra(a, 1);
	}

	sort_3(a);

	if (*b && (*b)->next && (*b)->value < (*b)->next->value)
		sb(b, 1);

	while (*b)
		pa(a, b, 1);
}