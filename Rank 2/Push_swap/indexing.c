/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 02:27:44 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/22 03:04:03 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node *get_min_node(t_node *a)
{
	long min = LONG_MAX;
	t_node *node = NULL;

	while (a)
	{
		if (a->index == -1 && a->value < min)
		{
			min = a->value;
			node = a;
		}
		a = a->next;
	}
	return (node);
}

void assign_index(t_node *a)
{
	int size = stack_size(a);
	int i = 0;
	t_node *min_node;
	t_node *tmp = a;

	while (tmp)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}

	while (i < size)
	{
		min_node = get_min_node(a);
		if (!min_node)
			return;
		min_node->index = i;
		i++;
	}
}