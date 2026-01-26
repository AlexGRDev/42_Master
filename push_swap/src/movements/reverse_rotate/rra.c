/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:58:26 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/25 20:58:53 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	int	tmp;

	if (stack->len_a < 2)
		return ;
	tmp = *(stack->a + stack->len_a - 1);
	ft_memmove(stack->a + 1, stack->a, (stack->len_a - 1) * sizeof(int));
	*(stack->a) = tmp;
	ft_printf("rra\n");
}
