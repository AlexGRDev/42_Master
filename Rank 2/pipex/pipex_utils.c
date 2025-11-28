/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:01:59 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/28 18:51:34 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>

void    child_one(char *cmd, char *infile, int *pipefd, char **envp)
{
    int        fd;
    char    *path;
    char    **args;

    fd = open(infile, O_RDONLY);
    if (fd < 0)
        perror(infile);
    if (dup2(fd, 0) == -1)
        perror("dup2");
    close(fd);
    if (dup2(pipefd[1], 1) == -1)
        perror("dup2");
    close(pipefd[0]);
    close(pipefd[1]);
    args = ft_split(cmd, ' ');
    path = get_cmd_path(args[0], &envp[0]);
    execve(path, args, &envp[0]);
    perror("execve");
    free(path);
    free_split(args);
    exit(127);
}

char    *get_cmd_path(char *cmd, char **envp)
{
    char    *candidate;
    char    *path_line;
    char    **paths;
    char    **paths_start;

    path_line = NULL;
    while (*envp)
    {
        if (!ft_strncmp(*envp, "PATH=", 5))
        {
            path_line = &(*envp)[5];
            break ;
        }
        envp++;
    }
    if (!path_line)
        return (ft_strdup(cmd));
    paths = ft_split(path_line, ':');
    if (!paths)
        return (ft_strdup(cmd));
    paths_start = paths;
    while (*paths)
    {
        candidate = ft_strjoin_three(*paths, "/", cmd);
        if (!candidate)
            break ;
        if (access(candidate, X_OK) == 0)
            return (free_split(paths_start), candidate);
        free(candidate);
        paths++;
    }
    free_split(paths_start);
    return (ft_strdup(cmd));
}

char    *ft_strjoin_three(char *a, char *b, char *c)
{
    char    *tmp;
    char    *res;

    tmp = ft_strjoin(a, b);
    if (!tmp)
        return (NULL);
    res = ft_strjoin(tmp, c);
    free(tmp);
    return (res);
}

void    free_split(char **arr)
{
    char    **tmp;

    if (!arr)
        return ;
    tmp = arr;
    while (*tmp)
        free(*tmp++);
    free(arr);
}

void    child_two(char *cmd, char *outfile, int *pipefd, char **envp)
{
    int        fd;
    char    *path;
    char    **args;

    fd = open(outfile, O_CREAT | O_TRUNC | O_WRONLY, 0660);
    if (fd < 0)
        perror(outfile);
    if (dup2(fd, STDOUT_FILENO) == -1)
        perror("dup2");
    close(fd);
    if (dup2(pipefd[0], STDIN_FILENO) == -1)
        perror("dup2");
    close(pipefd[0]);
    close(pipefd[1]);
    args = ft_split(cmd, ' ');
    if (!args)
        exit(1);
    path = get_cmd_path(args[0], &envp[0]);
    execve(path, args, &envp[0]);
    perror("execve");
    free(path);
    free_split(args);
    exit(127);
}
