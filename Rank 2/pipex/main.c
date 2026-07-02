/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:10:00 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/28 19:27:58 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_printf("Usage: %s infile cmd1 cmd2 outfile\n", argv[0]);
		return (1);
	}
	return (pipex(&argv[0], &envp[1]));
}
