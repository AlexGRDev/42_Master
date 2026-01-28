/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:38:36 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/28 15:38:52 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <limits.h>

typedef struct s_pair
{
	int	value;
	int	pos;
	int	i;
	int	j;
	int	k;
}	t_pair;

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
}	t_stack;

typedef struct s_chunk
{
	int	*cheap;
	int	*cost;
	int	*cost_a;
	int	*cost_b;
	int	*move;
	int	*pos;
	int	*target;
}	t_chunk;

int		parse(int argc, char **argv, t_stack *stack);
char	**ps_prepare_args(int argc, char **argv);
char	**ps_clean_empty(char **args);
void	ps_clean_spaces(char *s);
int		ps_validate(char **args);
int		ps_count(char **args);
int		ps_init_stack(t_stack *stack, int len);
void	ps_args_to_stack(int *stack_a, char **args);
void	ps_free_args(char **args);

char	*ft_strjoin_free(char *s1, char *s2);

void	pb(t_stack *s);
void	pa(t_stack *s);
void	sa(t_stack *s);
void	sb(t_stack *s);
void	ss(t_stack *s);
void	ra(t_stack *s);
void	rb(t_stack *s);
void	rr(t_stack *s);
void	rra(t_stack *s);
void	rrb(t_stack *s);
void	rrr(t_stack *s);

void	sort_2(t_stack *s);
void	sort_3(t_stack *s);

int		get_chunk_size(int len);
void	push_chunks_to_b(t_stack *s);
void	push_swap_sort(t_stack *s);

t_chunk	*chunk_init(t_stack *s);
void	free_chunks(t_chunk *c);

void	chunk_calc_positions(t_chunk *c, t_stack *s);
void	chunk_calc_target(t_chunk *c, t_stack *s);
void	chunk_calc_costs(t_chunk *c, t_stack *s);
int		find_cheapest(t_chunk *c, t_stack *s);
void	chunk_do_cheapest_move(t_chunk *c, t_stack *s);

void	assign_index(t_stack *s, int *index);
void	sort_big(t_stack *s);
void	sort_mid(t_stack *s);

#endif