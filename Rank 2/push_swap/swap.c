/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 19:10:08 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/29 19:31:47 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a)
{
	t_node	*tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = (*a)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	t_node	*tmp;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp = (*b)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (a && *a && (*a)->next)
	{
		tmp = (*a)->next;
		tmp->next = *a;
		*a = tmp;
	}
	if (b && *b && (*b)->next)
	{
		tmp = (*b)->next;
		tmp->next = *b;
		*b = tmp;
	}
	write(1, "ss\n", 3);
}
