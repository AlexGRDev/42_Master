/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:14:43 by agarcia2          #+#    #+#             */
/*   Updated: 2026/02/03 15:57:53 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "push_swap.h"

void	debug_print_stacks(t_stack *s, char *msg);
int		debug_is_sorted(t_stack *s);
void	debug_check_sorted(t_stack *s);
void	debug_print_chunk(t_chunk *c, t_stack *s);
void	debug_print_cheapest(t_chunk *c, t_stack *s);
void	debug_final_state(t_stack *s);
void	debug_op(char *op, t_stack *s);

#endif
