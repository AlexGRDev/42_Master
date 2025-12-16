/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:03:53 by agarcia2          #+#    #+#             */
/*   Updated: 2025/12/12 11:31:43 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "get_next_line.h"

static int	gnl_fill(int fd, char **stash)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	bytes;

	bytes = 1;
	if (!*stash)
	{
		*stash = gnl_substr("", 0, 0);
		if (!*stash)
			return (-1);
	}
	while (!gnl_strchr(*stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (-1);
		buf[bytes] = '\0';
		if (bytes > 0)
			*stash = gnl_strjoin(*stash, buf);
		if (!*stash)
			return (-1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (gnl_fill(fd, &stash) < 0)
		return (NULL);
	line = gnl_split_line(&stash);
	if (!line && stash)
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}
