/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:50:51 by agarcia2          #+#    #+#             */
/*   Updated: 2025/10/23 11:05:00 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static int	assign_split(char **dst, const char *start, const char *end)
{
	*dst = ft_substr(start, 0, (size_t)(end - start));
	if (!*dst)
		return (0);
	return (1);
}

static void	*free_all(char **arr)
{
	char	**tmp;

	if (!arr)
		return (NULL);
	tmp = arr;
	while (*tmp)
		free(*tmp++);
	free(arr);
	return (NULL);
}

static char	**fill_split(char **split, char const *s, char c)
{
	char		**ptr;
	const char	*start;

	ptr = split;
	while (*s)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		if (s > start)
		{
			if (!assign_split(ptr, start, s))
			{
				*ptr = NULL;
				return (free_all(split));
			}
			ptr++;
		}
	}
	*ptr = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	return (fill_split(split, s, c));
}
