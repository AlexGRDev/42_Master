/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:33:00 by agarcia2          #+#    #+#             */
/*   Updated: 2026/02/02 23:42:04 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int len)
{
	if (len <= 100)
		return (20);
	return (45);
}

void	push_swap_sort(t_stack *s)
{
	if (s->len_a <= 1)
		return ;
	if (s->len_a == 2)
		return (sort_2(s));
	if (s->len_a == 3)
		return (sort_3(s));
	if (s->len_a <= 15)
		return (sort_mid(s));
	return (sort_big(s));
}
