/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 00:41:57 by agarcia2          #+#    #+#             */
/*   Updated: 2026/02/08 16:36:46 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_has_empty_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (1);
		i++;
	}
	return (0);
}

static char	*ps_join_all(int argc, char **argv)
{
	char	*joined;
	int		i;

	joined = ft_strdup(argv[1]);
	if (!joined)
		return (NULL);
	i = 2;
	while (i < argc)
	{
		joined = ft_strjoin_free(joined, " ");
		if (!joined)
			return (NULL);
		joined = ft_strjoin_free(joined, argv[i]);
		if (!joined)
			return (NULL);
		i++;
	}
	return (joined);
}

char	**ps_prepare_args(int argc, char **argv)
{
	char	*line;
	char	**args;

	if (argc > 2 && ps_has_empty_arg(argc, argv))
		return (NULL);
	if (argc == 2)
	{
		line = ft_strdup(argv[1]);
		if (!line)
			return (NULL);
		ps_clean_spaces(line);
		args = ft_split(line, ' ');
		free(line);
		return (args);
	}
	line = ps_join_all(argc, argv);
	if (!line)
		return (NULL);
	args = ft_split(line, ' ');
	free(line);
	return (args);
}
