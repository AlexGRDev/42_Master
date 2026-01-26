/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 21:00:32 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/25 21:26:55 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *stack)
{
	int	tmp;

	if (stack->len_a >= 2)
	{
		tmp = *(stack->a + stack->len_a - 1);
		ft_memmove(stack->a + 1, stack->a, (stack->len_a - 1) * sizeof(int));
		*(stack->a) = tmp;
	}
	if (stack->len_b >= 2)
	{
		tmp = *(stack->b + stack->len_b - 1);
		ft_memmove(stack->b + 1, stack->b, (stack->len_b - 1) * sizeof(int));
		*(stack->b) = tmp;
	}
	ft_printf("rrr\n");
}
