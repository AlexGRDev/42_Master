/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 23:10:50 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/29 23:21:23 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_a(t_node **a, int val)
{
	int	pos;
	int	size;

	pos = find_pos(a, val);
	size = stack_size(a, *a);
	if (pos <= size / 2)
		return (pos);
	return (size - pos);
}

int	target_pos_b(t_node **b, int val)
{
	int		pos;
	t_node	*tmp;

	pos = 0;
	tmp = *b;
	if (!*b)
		return (0);
	if (val > find_max(b))
		return (0);
	if (val < find_min(b))
		return (stack_size(b, *b));
	while (tmp->next)
	{
		if (tmp->value > val && tmp->next->value < val)
			return (pos + 1);
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

int	cost_b(t_node **b, int val)
{
	int	pos;
	int	size;

	pos = target_pos_b(b, val);
	size = stack_size(b, *b);
	if (pos <= size / 2)
		return (pos);
	return (size - pos);
}

int	dir_a(t_node **a, int val)
{
	int	pos;

	pos = find_pos(a, val);
	if (pos <= stack_size(a, *a) / 2)
		return (1);
	return (-1);
}
