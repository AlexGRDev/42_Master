/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 19:31:59 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/29 19:40:47 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!b || !*b)
		return ;
	tmp = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!a || !*a)
		return ;
	tmp = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
}
