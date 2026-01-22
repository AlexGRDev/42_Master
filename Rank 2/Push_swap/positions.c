/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 02:15:25 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/22 02:16:34 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_positions(t_node *stack)
{
	int		pos;
	t_node	*tmp;

	pos = 0;
	tmp = stack;
	while (tmp)
	{
		tmp->pos = pos;
		tmp = tmp->next;
		pos++;
	}
}

int	get_target_pos(t_node *a, int index_b)
{
	t_node	*tmp = a;
	int		target_index = 2147483647;
	int		target_pos = 0;

	while (tmp)
	{
		if (tmp->index > index_b && tmp->index < target_index)
		{
			target_index = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (target_index == 2147483647)
	{
		tmp = a;
		target_index = 2147483647;
		while (tmp)
		{
			if (tmp->index < target_index)
			{
				target_index = tmp->index;
				target_pos = tmp->pos;
			}
			tmp = tmp->next;
		}
	}
	return (target_pos);
}

void	assign_target_positions(t_node *a, t_node *b)
{
	t_node	*tmp_b;

	update_positions(a);
	update_positions(b);

	tmp_b = b;
	while (tmp_b)
	{
		tmp_b->target_pos = get_target_pos(a, tmp_b->index);
		tmp_b = tmp_b->next;
	}
}