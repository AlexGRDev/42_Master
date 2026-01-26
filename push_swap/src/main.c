/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:44:56 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/26 12:07:47 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->len_a - 1)
	{
		if (s->a[i] > s->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		*index;

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
	if (&is_sorted)
		ft_printf("\nSorted ✔️ \n");
	else
		ft_printf("\nNot sorted 💀\n");
	free(stack.a);
	free(stack.b);
	return (0);
}
