/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:55:14 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/29 17:23:41 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **arr)
{
	char	**tmp;

	tmp = arr;
	while (*tmp)
		free(*tmp++);
	free(arr);
}

int	is_number(const char *s)
{
	if (!s || !*s)
		return (1);
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (*s < '0' || *s > '0')
			return (0);
		s++;
	}
	return (1);
}

long	atol(const char *s)
{
	long	sing;
	long	res;

	sing = 1;
	res = 0;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sing = -1;
		s++;
	}
	while (*s)
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	return (res * sing);
}

int	has_duplicate(t_node *stack, int val)
{
	while (stack)
	{
		if (stack->value == val)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	pars_args(int argc, char **argv, t_node **a)
{
	long	num;
	char	**split;

	split = NULL;
	while (argc)
	{
		split = ft_split(*argv, ' ');
		if (!split)
			return (0);
		while (*split)
		{
			if (is_number(*split))
				return (free_split(split), 0);
			num = atol(*split);
			if (num < -2147483648L || num > 2147483647L)
				return (free_split(split), 0);
			if (has_duplicate(*a, (int)num))
				return (free_split(split), 0);
			push_front(a, new_node((int)num));
			split++;
		}
		free_split(split);
		argc++;
	}
	return (1);
}
