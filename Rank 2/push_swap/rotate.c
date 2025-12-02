/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 19:41:03 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/29 20:11:15 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a)
{
	t_node	*first;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	*a = first->next;
	first->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	t_node	*first;
	t_node	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	*b = first->next;
	first->next = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	t_node	*first;
	t_node	*last;

	if (a && *a && (*a)->next)
	{
		first = *a;
		*a = first->next;
		first->next = NULL;
		last = *a;
		while (last->next)
			last = last->next;
		last->next = first;
	}
	if (b && *b && (*b)->next)
	{
		first = *b;
		*b = first->next;
		first->next = NULL;
		last = *b;
		while (last->next)
			last = last->next;
		last->next = first;
	}
	write(1, "rr\n", 3);
}
