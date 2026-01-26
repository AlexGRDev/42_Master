/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:46:50 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/26 00:43:39 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *s)
{
	if (s->len_b == 0)
		return ;
	ft_memmove(s->a + 1, s->a, s->len_a * sizeof(int));
	s->a[0] = s->b[0];
	ft_memmove(s->b, s->b + 1, (s->len_b - 1) * sizeof(int));
	s->len_b--;
	s->len_a++;
	ft_printf("pa\n");
}
