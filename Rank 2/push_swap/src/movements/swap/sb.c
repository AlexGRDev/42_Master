/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:53:09 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/25 21:27:24 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *stack)
{
	int	tmp;

	if (stack->len_b < 2)
		return ;
	tmp = *(stack->b);
	*(stack->b) = *(stack->b + 1);
	*(stack->b + 1) = tmp;
	ft_printf("sb\n");
}
