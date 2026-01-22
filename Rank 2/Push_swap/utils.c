/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 02:24:27 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/22 02:24:29 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void append_node(t_node **stack, int value)
{
	t_node *new = malloc(sizeof(t_node));
	t_node *tmp;

	new->value = value;
	new->index = -1;
	new->next = NULL;

	if (!*stack)
	{
		*stack = new;
		return;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int stack_size(t_node *s)
{
	int n = 0;
	while (s)
	{
		s = s->next;
		n++;
	}
	return (n);
}

void free_stack(t_node **stack)
{
	t_node *tmp;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int has_duplicates(t_node *a)
{
	t_node *x, *y;

	x = a;
	while (x)
	{
		y = x->next;
		while (y)
		{
			if (x->value == y->value)
				return (1);
			y = y->next;
		}
		x = x->next;
	}
	return (0);
}

void error_exit(t_node **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}