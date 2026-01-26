/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:57:22 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/25 20:57:42 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *stack)
{
	int	tmp;

	if (stack->len_a >= 2)
	{
		tmp = *(stack->a);
		ft_memmove(stack->a, stack->a + 1, (stack->len_a - 1) * sizeof(int));
		*(stack->a + stack->len_a - 1) = tmp;
	}
	if (stack->len_b >= 2)
	{
		tmp = *(stack->b);
		ft_memmove(stack->b, stack->b + 1, (stack->len_b - 1) * sizeof(int));
		*(stack->b + stack->len_b - 1) = tmp;
	}
	ft_printf("rr\n");
}
