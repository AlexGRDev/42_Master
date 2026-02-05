/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:09:32 by agarcia2          #+#    #+#             */
/*   Updated: 2026/02/03 16:09:52 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	debug_final_state(t_stack *s)
{
	ft_printf("\n=== ESTADO FINAL ===\n");
	debug_print_stacks(s, "Final");
	debug_check_sorted(s);
}

void	debug_op(char *op, t_stack *s)
{
	ft_printf("OP: %s\n", op);
	debug_print_stacks(s, "Después de operación");
}
