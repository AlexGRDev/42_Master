/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 21:30:45 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/29 21:46:26 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a)
{
	t_node	*last;
	t_node	*prev;

	if (!a || !*a || !(*a)->next)
		return ;
	last = *a;
	prev = NULL;
	while (last->next)
	{
		prev = last->next;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	t_node	*last;
	t_node	*prev;

	if (!b || !*b || (*b)->next)
		return ;
	last = *b;
	prev = NULL;
	while (last->next)
	{
		prev = last->next;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	t_node	*last;
	t_node	*prev;

	if (a && *a && (*a)->next)
	{
		last = *a;
		prev = NULL;
		while (last->next)
		{
			prev = last->next;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *a;
		*a = last;
	}
	if (b && *b && (*b)->next)
	{
		last = *b;
		prev = NULL;
		while (last->next)
		{
			prev = last->next;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *b;
		*b = last;
	}
	write(1, "rrr\n", 
}
