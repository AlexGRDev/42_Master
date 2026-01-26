/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:56:26 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/25 20:57:00 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack *stack)
{
	int	tmp;

	if (stack->len_b < 2)
		return ;
	tmp = *(stack->b);
	ft_memmove(stack->b, stack->b + 1, (stack->len_b - 1) * sizeof(int));
	*(stack->b + stack->len_b - 1) = tmp;
	ft_printf("rb\n");
}
