/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:17:29 by agarcia2          #+#    #+#             */
/*   Updated: 2025/09/23 15:20:15 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_is_negative(int n)
{
	char	_p;
	char	_n;

	_p = 'P';
	_n = 'N';
	if (n >= 0)
		ft_putchar(_p);
	else
		ft_putchar(_n);
}
