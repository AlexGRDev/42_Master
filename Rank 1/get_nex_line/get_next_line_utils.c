/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:04:04 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/20 16:20:00 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*gnl_substr(const char *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	slen = gnl_strlen(s);
	if (start >= slen)
		len = 0;
	else if (len > slen - start)
		len = slen - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*gnl_strjoin(char *s1, const char *s2)
{
	char	*joined;
	size_t	len1;
	size_t	i;

	len1 = gnl_strlen(s1);
	joined = (char *)malloc(len1 + gnl_strlen(s2) + 1);
	if (!joined)
	{
		free(s1);
		return (NULL);
	}
	i = len1;
	while (i--)
		joined[i] = s1[i];
	i = len1;
	while (*s2)
		joined[i++] = *s2++;
	joined[i] = '\0';
	free(s1);
	return (joined);
}

char	*gnl_split_line(char **stash)
{
	char	*nl;
	char	*line;
	char	*rest;
	size_t	len;

	if (!stash || !*stash || !**stash)
		return (NULL);
	nl = gnl_strchr(*stash, '\n');
	if (!nl)
	{
		line = *stash;
		*stash = NULL;
		return (line);
	}
	len = (size_t)(nl - *stash) + 1;
	line = gnl_substr(*stash, 0, len);
	if (!line)
		return (NULL);
	rest = gnl_substr(*stash, (unsigned int)len, gnl_strlen(*stash) - len);
	free(*stash);
	*stash = rest;
	return (line);
}
