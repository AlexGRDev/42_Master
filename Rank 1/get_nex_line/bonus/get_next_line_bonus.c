/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 14:00:00 by agarcia2          #+#    #+#             */
/*   Updated: 2026/07/17 14:11:07 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"

static int	gnl_read_append(int fd, char *buf, char **bytes, size_t *cap)
{
	ssize_t	nread;

	nread = read(fd, buf, BUFFER_SIZE - 1);
	if (nread <= 0)
		return ((int)nread);
	*(buf + nread) = '\0';
	*bytes = ft_bytes_join(*bytes, buf, cap);
	if (!*bytes)
		return (-1);
	return (1);
}

static char	*read_to_bytes(int fd, char *bytes)
{
	char	*buf;
	int		status;
	size_t	len;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(bytes), NULL);
	len = ft_strlen_gnl(bytes) + 1;
	status = 1;
	while (!ft_strchr_gnl(bytes, '\n') && status > 0)
		status = gnl_read_append(fd, buf, &bytes, &len);
	if (status < 0)
	{
		free(buf);
		buf = NULL;
		free(bytes);
		bytes = NULL;
		return (NULL);
	}
	free(buf);
	buf = NULL;
	return (bytes);
}

static char	*extract_line(char *bytes)
{
	char	*line;
	char	*src;
	char	*dst;
	size_t	len;

	if (!bytes || !*bytes)
		return (NULL);
	src = bytes;
	len = 0;
	while (*src && *src != '\n')
	{
		src++;
		len++;
	}
	if (*src == '\n')
		len++;
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	dst = line;
	src = bytes;
	while (len--)
		*dst++ = *src++;
	*dst = '\0';
	return (line);
}

static char	*clean_bytes(char *bytes)
{
	char	*nl;
	char	*dst;
	char	*src;

	if (!bytes)
		return (NULL);
	nl = ft_strchr_gnl(bytes, '\n');
	if (!nl)
	{
		free(bytes);
		bytes = NULL;
		return (NULL);
	}
	dst = bytes;
	src = nl + 1;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (bytes);
}

char	*get_next_line(int fd)
{
	static char	*bytes[FD_MAX];
	char		*line;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	bytes[fd] = read_to_bytes(fd, bytes[fd]);
	if (!bytes[fd])
		return (NULL);
	line = extract_line(bytes[fd]);
	if (!line)
	{
		free(bytes[fd]);
		bytes[fd] = NULL;
		return (NULL);
	}
	bytes[fd] = clean_bytes(bytes[fd]);
	return (line);
}
