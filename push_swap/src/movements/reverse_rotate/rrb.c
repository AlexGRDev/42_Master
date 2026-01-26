/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:59:48 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/25 21:00:10 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack *stack)
{
	int	tmp;

	if (stack->len_b < 2)
		return ;
	tmp = *(stack->b + stack->len_b - 1);
	ft_memmove(stack->b + 1, stack->b, (stack->len_b - 1) * sizeof(int));
	*(stack->b) = tmp;
	ft_printf("rrb\n");
}
