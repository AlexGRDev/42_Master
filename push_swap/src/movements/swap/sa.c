/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:50:14 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/25 21:27:37 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	tmp;

	if (stack->len_a < 2)
		return ;
	tmp = *(stack->a);
	*(stack->a) = *(stack->a + 1);
	*(stack->a + 1) = tmp;
	ft_printf("sa\n");
}
