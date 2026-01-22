/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 02:26:36 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/22 03:01:02 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_to_b(t_node **a, t_node **b)
{
	int size = stack_size(*a);

	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, 1);
		return;
	}

	if (size == 3)
	{
		sort_3(a);
		return;
	}

	if (size <= 5)
	{
		sort_5(a, b);
		return;
	}

	push_all_to_b(a, b);
}