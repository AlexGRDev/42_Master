/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:25:26 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/26 00:43:30 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *s)
{
	if (s->len_a == 0)
		return ;
	ft_memmove(s->b + 1, s->b, s->len_b * sizeof(int));
	s->b[0] = s->a[0];
	ft_memmove(s->a, s->a + 1, (s->len_a - 1) * sizeof(int));
	s->len_a--;
	s->len_b++;
	ft_printf("pb\n");
}
