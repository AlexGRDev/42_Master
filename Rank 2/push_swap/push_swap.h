/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:09:17 by agarcia2          #+#    #+#             */
/*   Updated: 2025/11/29 23:08:37 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/LibFT/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}		t_node;

t_node	*new_node(int value);
void	push_front(t_node **stack, t_node *node);
void	free_stack(t_node **stack);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	sort_chuncks(t_node **a, t_node **b);
void	rotate_to_top(t_node **stack, char name, int target);
long	ft_atol(const char *s);
int		stack_size(t_node **stack, t_node *node);
int		find_min(t_node **stack);
int		find_max(t_node **stack);
int		find_pos(t_node **stack, int target);
int		parse_args(int argc, char **argv, t_node **a);
int		is_number(const char *s);
int		has_duplicate(t_node *stack, int val);
int		exists_in_range(t_node **stack, int lo, int hi);
int		*stack_to_sorted_arry(t_node *a);
#endif
