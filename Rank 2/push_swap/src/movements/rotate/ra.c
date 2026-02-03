/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:55:31 by agarcia2          #+#    #+#             */
/*   Updated: 2026/02/02 20:39:47 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	int	tmp;

	if (stack->len_a < 2)
		return ;
	tmp = *(stack->a);
	ft_memmove(stack->a, stack->a + 1, (stack->len_a - 1) * sizeof(int));
	*(stack->a + stack->len_a - 1) = tmp;
	ft_printf("ra\n");
}
