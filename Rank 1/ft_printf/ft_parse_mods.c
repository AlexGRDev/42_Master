/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_mods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:11:28 by agarcia2          #+#    #+#             */
/*   Updated: 2026/07/20 17:40:00 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_minus(t_mods *mods)
{
	mods->minus = 1;
}

static void	set_zero(t_mods *mods)
{
	mods->zero = 1;
}

static void	parse_width_prec(const char **fmt, t_mods *mods)
{
	mods->width = 0;
	while (**fmt >= '0' && **fmt <= '9')
		mods->width = mods->width * 10 + (*(*fmt)++ - '0');
	mods->prec = -1;
	if (**fmt == '.')
	{
		(*fmt)++;
		mods->prec = 0;
		while (**fmt >= '0' && **fmt <= '9')
			mods->prec = mods->prec * 10 + (*(*fmt)++ - '0');
	}
}

void	parse_mods(const char **fmt, t_mods *mods)
{
	t_modtable	flag_table[3];
	int			i;

	flag_table[0] = (t_modtable){'-', set_minus};
	flag_table[1] = (t_modtable){'0', set_zero};
	flag_table[2] = (t_modtable){0, NULL};
	mods->minus = 0;
	mods->zero = 0;
	while (**fmt == '-' || **fmt == '0')
	{
		i = 0;
		while (flag_table[i].flag && flag_table[i].flag != **fmt)
			i++;
		if (flag_table[i].apply_fn)
			flag_table[i].apply_fn(mods);
		(*fmt)++;
	}
	parse_width_prec(fmt, mods);
}
