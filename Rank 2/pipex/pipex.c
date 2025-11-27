/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:12:20 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/27 11:02:19 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>

int	pipex(char **argv, char **envp)
{
	int		pipefd[2];
	int		status;
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	pid1 = fork();
	if (pid1 < 0)
		return (perror("fork"), 1);
	if (pid1 == 0)
	{
		child_one(argv[1], argv[2], &pipefd[0], &envp[0]);
		exit(1);
	}
	pid2 = fork();
	if (pid2 < 0)
		return (perror("fork"), 1);
	if (pid2 == 0)
	{
		child_two(argv[4], argv[3], &pipefd[0], &envp[0]);
		exit(1);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
