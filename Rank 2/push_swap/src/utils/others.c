/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:45:55 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/26 09:18:43 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_free(char **args)
{
	int	i;

	write(2, "Error\n", 6);
	if (!args)
		return (0);
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	return (0);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char *join;

	if (!s1 || !s2)
		return (NULL);
	join = ft_strjoin(s1, s2);
	free(s1);
	return (join);
}

void	free_args(char **args)
{
	int	i;

	if (!args)
		return;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	free_chunks(t_chunk *c)
{
	if (!c)
		return;
	free(c->cheap);
	free(c->cost);
	free(c->cost_a);
	free(c->cost_b);
	free(c->move);
	free(c->pos);
	free(c->target);
	free(c);
}