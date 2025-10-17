/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:17:48 by agarcia2          #+#    #+#             */
/*   Updated: 2025/10/09 11:55:55 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	count;

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

static char	*word_dup(const char *start, const char *end)
{
	char	*word;

	word = malloc(end - start + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, start, end - start);
	word[end - start] = '\0';
	return (word);
}

static void	*free_all(char **arr)
{
	char	**tmp;

	tmp = arr;
	while (*tmp)
		free(*tmp++);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	char		**ptr;
	const char	*start;

	split = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
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
			*ptr = word_dup(start, s);
			if (!*ptr)
				return (free_all(split));
			ptr++;
		}
	}
	*ptr = NULL;
	return (split);
}
