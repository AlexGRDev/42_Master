/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 00:42:50 by agarcia2          #+#    #+#             */
/*   Updated: 2026/02/06 15:19:55 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_isnumber(const char *s, int *out)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (!ft_isdigit(*s))
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		num = num * 10 + (*s - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && - num < INT_MIN))
			return (0);
		s++;
	}
	*out = (int)(num * sign);
	return (1);
}

static int	ps_has_duplicate(char **args)
{
	int	i;
	int	j;
	int	a;
	int	b;

	i = 0;
	while (args[i])
	{
		ps_isnumber(args[i], &a);
		j = i + 1;
		while (args[j])
		{
			ps_isnumber(args[j], &b);
			if (a == b)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ps_validate(char **args)
{
	int	i;
	int	tmp;

	i = 0;
	while (args[i])
	{
		if (!ps_isnumber(args[i], &tmp))
			return (write(2, "Error\n", 6), 0);
		i++;
	}
	if (ps_has_duplicate(args))
		return (write(2, "Error\n", 6), 0);
	return (1);
}
