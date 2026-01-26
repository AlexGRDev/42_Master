/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:02:57 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/26 11:22:54 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge(t_pair *arr, int left, int mid, int right)
{
	int		i;
	int		j;
	int		k;
	t_pair	*tmp;

	tmp = malloc(sizeof(t_pair) * (right - left + 1));
	if (!tmp)
		return ;
	i = left;
	j = mid + 1;
	k = 0;
	while (i <= mid && j <= right)
	{
		if (arr[i].value < arr[j].value)
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}
	while (i <= mid)
		tmp[k++] = arr[i++];
	while (j <= right)
		tmp[k++] = arr[j++];
	i = 0;
	while (left <= right)
		arr[left++] = tmp[i++];
	free(tmp);
}

static void	merge_sort(t_pair *arr, int left, int right)
{
	int	mid;

	if (left >= right)
		return ;
	mid = (left + right) / 2;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

void	assign_index(t_stack *s, int *index)
{
	t_pair	*tmp;
	int		i;

	tmp = malloc(sizeof(t_pair) * s->len_a);
	if (!tmp)
		return ;
	i = 0;
	while (i < s->len_a)
	{
		tmp[i].value = s->a[i];
		tmp[i].pos = i;
		i++;
	}
	merge_sort(tmp, 0, s->len_a - 1);
	i = 0;
	while (i < s->len_a)
	{
		index[tmp[i].pos] = i;
		i++;
	}
	free(tmp);
}
