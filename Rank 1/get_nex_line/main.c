/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:33:55 by agarcia2          #+#    #+#             */
/*   Updated: 2025/12/16 17:23:40 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("line:%s\n",line);
		free(line);
		line = get_next_line(fd);
	}
	printf("last line: %s\n", line);
	free(line);
	close(fd);
	return (0);
}
