/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:02:57 by agarcia2          #+#    #+#             */
/*   Updated: 2026/02/08 12:54:13 by agarcia2         ###   ########.fr       */
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
		tmp[k++] = (arr[i].value < arr[j].value) ? arr[i++] : arr[j++];
	while (i <= mid)
		tmp[k++] = arr[i++];
	while (j <= right)
		tmp[k++] = arr[j++];
	while (k--)
		arr[right--] = tmp[k];
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

void	assign_index(t_stack *stack, int *index)
{
	t_pair	*tmp;
	int		i;

	tmp = malloc(sizeof(t_pair) * stack->len_a);
	if (!tmp)
		return ;
	i = -1;
	while (++i < stack->len_a)
	{
		tmp[i].value = stack->a[i];
		tmp[i].pos = i;
	}
	merge_sort(tmp, 0, stack->len_a - 1);
	i = -1;
	while (++i < stack->len_a)
		index[tmp[i].pos] = i;
	free(tmp);
}
