/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:44:56 by agarcia2          #+#    #+#             */
/*   Updated: 2026/02/03 00:44:07 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack stack;
	int *index;

	stack.a = NULL;
	stack.b = NULL;
	if (!parse(argc, argv, &stack))
		return (1);
	index = ft_calloc(stack.len_a, sizeof(int));
	if (!index)
		return (free(stack.a), free(stack.b), 1);
	assign_index(&stack, index);
	ft_memcpy(stack.a, index, stack.len_a * sizeof(int));
	free(index);
	push_swap_sort(&stack);
	free(stack.a);
	free(stack.b);
	return (0);
}
