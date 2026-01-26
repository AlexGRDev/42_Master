/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:54:18 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/25 20:54:32 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *stack)
{
	int	tmp;

	if (stack->len_a >= 2)
	{
		tmp = *(stack->a);
		*(stack->a) = *(stack->a + 1);
		*(stack->a + 1) = tmp;
	}
	if (stack->len_b >= 2)
	{
		tmp = *(stack->b);
		*(stack->b) = *(stack->b + 1);
		*(stack->b + 1) = tmp;
	}
	ft_printf("ss\n");
}
