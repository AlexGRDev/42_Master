/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 03:13:46 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/22 11:48:35 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\v' || c == '\f');
}

static int	is_numeric(const char *s)
{
	int	i = 0;

	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static long	ft_atol(const char *s)
{
	long	sign = 1;
	long	res = 0;

	while (is_space(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s)
	{
		res = res * 10 + (*s - '0');
		if (res * sign > INT_MAX || res * sign < INT_MIN)
			return ((long)INT_MAX + 1);
		s++;
	}
	return (res * sign);
}


static char	**split_args(const char *s)
{
	char	**out;
	int		i = 0, k = 0, start = -1;

	out = malloc(sizeof(char *) * 2000);
	if (!out)
		return (NULL);
	while (s[i])
	{
		if (!is_space(s[i]) && start < 0)
			start = i;
		if ((is_space(s[i]) || s[i + 1] == '\0') && start >= 0)
		{
			int end = (is_space(s[i]) ? i : i + 1);
			int len = end - start;
			char *num = malloc(len + 1);
			int j = 0;
			while (j < len)
				num[j++] = s[start++];
			num[j] = '\0';
			out[k++] = num;
			start = -1;
		}
		i++;
	}
	out[k] = NULL;
	return (out);
}

static void	free_split(char **s)
{
	int	i = 0;

	if (!s)
		return ;
	while (s[i])
		free(s[i++]);
	free(s);
}

void	parse_args(int argc, char **argv, t_node **a)
{
	char	**nums;
	int		i = 0;
	long	val;

	if (argc == 2)
		nums = split_args(argv[1]);
	else
		nums = argv + 1;

	if (!nums)
		error_exit(a);

	while (nums[i])
	{
		if (!is_numeric(nums[i]))
		{
			free_split(nums);
			error_exit(a);
		}
		val = ft_atol(nums[i]);
		if (val == (long)INT_MAX + 1 || val == (long)INT_MIN + 1)
		{
			if (argc == 2)
				free_split(nums);
			error_exit(a);
		}
		append_node(a, (int)val);
		i++;
	}
	
	if (has_duplicates(*a))
		error_exit(a);
}