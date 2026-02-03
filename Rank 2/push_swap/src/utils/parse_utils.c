/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:22:39 by agarcia2          #+#    #+#             */
/*   Updated: 2026/02/03 00:28:52 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_count(char **args)
{
	int	n;

	n = 0;
	while (args[n])
		n++;
	return (n);
}

void ps_args_to_stack(t_stack *stack, char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		stack->a[i]= ft_atoi(args[i]);
		stack->original[i] = stack->a[i];
		i++;
	}
}

int	ps_init_stack(t_stack *st, int len)
{
	st->a = ft_calloc(len, sizeof(int));
	st->original =ft_calloc(len, sizeof(stack_t));
	if (!st->a)
		return (0);
	st->b = ft_calloc(len, sizeof(int));
	if (!st->b)
		return (free(st->a), 0);
	return (1);
}

void	ps_free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
