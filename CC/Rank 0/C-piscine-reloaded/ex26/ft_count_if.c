/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:53:49 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/10/10 16:23:34 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
int count_if(char *str) {
    int count = 0;
    while (*str) {
        if (*str == '1') {
            count++;
        }
        str++;
    }
    return count;
}
*/
int	ft_count_if(char **tab, int (*f)(char *))
{
	int	count;
	int	i;

	if (!tab)
		return (0);
	count = 0;
	i = -1;
	while (tab[++i])
	{
		if (f(tab[i]))
			count++;
	}
	return (count);
}
/*
#include <stdio.h>
int main(int ac, char **av)
{
	int count = ft_count_if(av+1, count_if);
	printf("%d\n", count);
	return 0;
}
*/