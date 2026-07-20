/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:28:00 by agarcia2          #+#    #+#             */
/*   Updated: 2026/07/20 12:45:40 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int ac, char **av)
{
	char	*c;
	int		ft;
	int		og;
	(void)ac;

	c = av[1];
	ft = ft_printf("ft: %s\n", c);
	og = printf("og: %s\n", c);
	if (ft == og)
		printf("OK (ft=%d og=%d)\n", ft, og);
	else
		printf("KO (ft=%d og=%d)\n", ft, og);
	return (0);
}
