/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 00:46:47 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/26 00:59:52 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_clean_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
			s[i] = ' ';
		i++;
	}
}

static int	ps_count_nonempty(char **args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (args[i])
	{
		if (args[i][0] != '\0')
			count++;
		i++;
	}
	return (count);
}

static void	ps_copy_nonempty(char **clean, char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[i])
	{
		if (args[i][0] != '\0')
			clean[j++] = args[i];
		else
			free(args[i]);
		i++;
	}
	clean[j] = NULL;
}

char	**ps_clean_empty(char **args)
{
	char	**clean;
	int		size;

	size = ps_count_nonempty(args);
	clean = ft_calloc(size + 1, sizeof(char *));
	if (!clean)
	{
		ps_free_args(args);
		return (NULL);
	}
	ps_copy_nonempty(clean, args);
	free(args);
	return (clean);
}
