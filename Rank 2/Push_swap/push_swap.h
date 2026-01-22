/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 02:23:13 by agarcia2          #+#    #+#             */
/*   Updated: 2026/01/22 02:32:45 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_node
{
    int value;
    int index;
    int pos;
    int target_pos;
    int cost_a;
    int cost_b;
    struct s_node *next;
} t_node;

int ps_atoi(const char *str, int *error);
int is_number(const char *str);
void parse_args(int argc, char **argv, t_node **a);
int has_duplicates(t_node *a);
void error_exit(t_node **a);
void append_node(t_node **stack, int value);
void free_stack(t_node **stack);
int stack_size(t_node *stack);
void sa(t_node **a, int print);
void sb(t_node **b, int print);
void ss(t_node **a, t_node **b, int print);
void pa(t_node **a, t_node **b, int print);
void pb(t_node **a, t_node **b, int print);
void ra(t_node **a, int print);
void rb(t_node **b, int print);
void rr(t_node **a, t_node **b, int print);
void rra(t_node **a, int print);
void rrb(t_node **b, int print);
void rrr(t_node **a, t_node **b, int print);
void assign_index(t_node *a);
void update_positions(t_node *stack);
int get_target_pos(t_node *a, int index_b);
void assign_target_positions(t_node *a, t_node *b);
void calculate_costs(t_node *a, t_node *b);
t_node *get_cheapest_move(t_node *b);
void do_cheapest_move(t_node **a, t_node **b, t_node *n);
void sort_stacks(t_node **a, t_node **b);
void push_all_to_b(t_node **a, t_node **b);
void push_to_b(t_node **a, t_node **b);
void    sort_2(t_node **a);
void    sort_3(t_node **a);
void    sort_5(t_node **a, t_node **b);
#endif