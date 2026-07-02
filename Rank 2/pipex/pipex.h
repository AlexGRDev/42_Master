/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:14:04 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/27 11:18:39 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "ft_printf/LibFT/libft.h"
# include "ft_printf/ft_printf.h"

/* pipex.c */
int		pipex(char **argv, char **envp);

/* pipex_utils.c */
char	*get_cmd_path(char *cmd, char **envp);
char	*ft_strjoin_three(char *a, char *b, char *c);
void	free_split(char **arr);

/* children */
void	child_one(char *infile, char *cmd1, int *pipefd, char **envp);
void	child_two(char *outfile, char *cmd2, int *pipefd, char **envp);

#endif
