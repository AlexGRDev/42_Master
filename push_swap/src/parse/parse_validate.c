/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    parse_validate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 00:42:50 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/26 00:43:04 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_isnumber(char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	if (!ft_isdigit(*s))
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

static int	ps_has_duplicate(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
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

	i = 0;
	while (args[i])
	{
		if (!ps_isnumber(args[i]))
			return (write(2, "Error\n", 6), 0);
		i++;
	}
	if (ps_has_duplicate(args))
		return (write(2, "Error\n", 6), 0);
	return (1);
}
