/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:17:12 by agarcia2          #+#    #+#             */
/*   Updated: 2026/07/20 16:26:03 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

# include "./LibFT/libft.h"

typedef struct formtaers
{
	char	*fmt;
	char	*(*conv_fn)(va_list *args);

}	t_fmt;

typedef struct s_mods
{
	int		minus;
	int		zero;
	int		width;
	int		prec;
	int		len;
	char	padc;
}	t_mods;

typedef struct s_modtable
{
	char	flag;
	void	(*apply_fn)(t_mods *mods);
}	t_modtable;

int		ft_printf(const char *fmt, ...);
void	parse_mods(const char **fmt, t_mods *mods);
void	init_formats(t_fmt *formats);
char	*ft_putchar(va_list *args);
char	*ft_putstr(va_list *args);
char	*ft_putnbr(va_list *args);
char	*ft_putptr(va_list *args);
char	*ft_putund(va_list *args);
char	*ft_puthex(va_list *args);
char	*ft_puthexmaj(va_list *args);
#endif
