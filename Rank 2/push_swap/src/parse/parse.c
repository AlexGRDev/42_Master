/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:06:25 by agarcia2          #+#    #+#             */
/*   Updated: 2026/02/03 00:27:43 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse(int argc, char **argv, t_stack *stack)
{
	char	**args;
	int		len;

	if (argc < 2)
		return (0);
	args = ps_prepare_args(argc, argv);
	if (!args)
		return (0);
	args = ps_clean_empty(args);
	if (!args)
		return (0);
	if (!ps_validate(args))
		return (ps_free_args(args), 0);
	len = ps_count(args);
	if (!ps_init_stack(stack, len))
		return (ps_free_args(args), 0);
	ps_args_to_stack(stack, args);
	stack->len_a = len;
	stack->len_b = 0;
	ps_free_args(args);
	return (1);
}
