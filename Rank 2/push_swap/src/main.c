/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:44:56 by agarcia2          #+#    #+#             */
/*   Updated: 2026/02/06 16:04:07 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_exit_if_sorted(t_stack *st)
{
	if (ps_is_sorted(st))
	{
		free(st->a);
		free(st->b);
		free(st->original);
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_stack	stack;
	int	*index;

	if (argc < 2)
		return (0);
	stack.a = NULL;
	stack.b = NULL;
	if (!parse(argc, argv, &stack))
		return (0);
	if (ps_exit_if_sorted(&stack))
		return (0);
	index = ft_calloc(stack.len_a, sizeof(int));
	if (!index)
		return (free(stack.a), free(stack.b), 1);
	assign_index(&stack, index);
	ft_memcpy(stack.a, index, stack.len_a * sizeof(int));
	free(index);
	push_swap_sort(&stack);
	free(stack.a);
	free(stack.b);
	free(stack.original);
	return (0);
}

