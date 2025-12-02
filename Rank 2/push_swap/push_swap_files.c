// ==== FILE: cost.c ====
#include "push_swap.h"

int cost_a(t_node **a, int val)
{
    int pos = find_pos(a, val);
    int size = stack_size(a, *a);
    if (pos <= size / 2)
        return pos;
    return size - pos;
}

int target_pos_b(t_node **b, int val)
{
    int pos = 0;
    t_node *tmp = *b;
    if (!*b)
        return 0;
    if (val > find_max(b))
        return 0;
    if (val < find_min(b))
        return stack_size(b, *b);
    while (tmp->next)
    {
        if (tmp->value > val && tmp->next->value < val)
            return pos + 1;
        tmp = tmp->next;
        pos++;
    }
    return pos;
}

int cost_b(t_node **b, int val)
{
    int pos = target_pos_b(b, val);
    int size = stack_size(b, *b);
    if (pos <= size / 2)
        return pos;
    return size - pos;
}

int dir_a(t_node **a, int val)
{
    int pos = find_pos(a, val);
    if (pos <= stack_size(a, *a) / 2)
        return 1;
    return -1;
}


// ==== FILE: cost2.c ====
#include "push_swap.h"

int dir_b(t_node **b, int val)
{
    int pos = target_pos_b(b, val);
    if (pos <= stack_size(b, *b) / 2)
        return 1;
    return -1;
}

int total_cost(t_node **a, t_node **b, int val)
{
    int ca = cost_a(a, val);
    int cb = cost_b(b, val);
    int da = dir_a(a, val);
    int db = dir_b(b, val);
    if (da == db)
        return (ca > cb ? ca : cb);
    return ca + cb;
}

int select_cheapest(t_node **a, t_node **b, int lo, int hi)
{
    t_node *tmp = *a;
    int best_val = 0;
    int best_cost = 2147483647;
    while (tmp)
    {
        if (tmp->value >= lo && tmp->value <= hi)
        {
            int cost = total_cost(a, b, tmp->value);
            if (cost < best_cost)
            {
                best_cost = cost;
                best_val = tmp->value;
            }
        }
        tmp = tmp->next;
    }
    return best_val;
}

void move_value(t_node **a, t_node **b, int val)
{
    int da = dir_a(a, val);
    int db = dir_b(b, val);
    while ((*a)->value != val && *b && db == da)
    {
        if (da == 1)
            rr(a, b);
        else
            rrr(a, b);
    }
    while ((*a)->value != val)
    {
        if (da == 1)
            ra(a);
        else
            rra(a);
    }
    int pos = target_pos_b(b, val);
    int size = stack_size(b, *b);
    if (pos <= size / 2)
        while (pos-- > 0)
            rb(b);
    else
        while ((size - pos++) > 0)
            rrb(b);
    pb(a, b);
}


// ==== FILE: chuncks.c ====
#include "push_swap.h"

void sort_chuncks(t_node **a, t_node **b)
{
    int n = stack_size(a, *a);
    int *arr = stack_to_shrted_arry(*a);
    int chunk_count = (n <= 100) ? 5 : 11;
    int chunk_size = n / chunk_count;

    int idx = 0;
    int lo, hi;

    for (int c = 0; c < chunk_count; c++)
    {
        lo = arr[idx];
        if (c == chunk_count - 1)
            hi = arr[n - 1];
        else
            hi = arr[idx + chunk_size - 1];

        while (exists_in_range(a, lo, hi))
        {
            int val = select_cheapest(a, b, lo, hi);
            move_value(a, b, val);
        }
        idx += chunk_size;
    }
    free(arr);

    while (*b)
    {
        int max = find_max(b);
        int pos = find_pos(b, max);
        int size = stack_size(b, *b);
        if (pos <= size / 2)
            while (pos-- > 0)
                rb(b);
        else
            while ((size - pos++) > 0)
                rrb(b);
        pa(a, b);
    }
}


// ==== FILE: utils_extra.c ====
#include "push_swap.h"

int exists_in_range(t_node **stack, int lo, int hi)
{
    t_node *tmp = *stack;
    while (tmp)
    {
        if (tmp->value >= lo && tmp->value <= hi)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

int find_pos(t_node **stack, int target)
{
    int i = 0;
    t_node *tmp = *stack;
    while (tmp)
    {
        if (tmp->value == target)
            return i;
        tmp = tmp->next;
        i++;
    }
    return -1;
}

int find_min(t_node **stack)
{
    t_node *tmp = *stack;
    int min = tmp->value;
    while (tmp)
    {
        if (tmp->value < min)
            min = tmp->value;
        tmp = tmp->next;
    }
    return min;
}

int find_max(t_node **stack)
{
    t_node *tmp = *stack;
    int max = tmp->value;
    while (tmp)
    {
        if (tmp->value > max)
            max = tmp->value;
        tmp = tmp->next;
    }
    return max;
}

// ==== END OF FILES ==== 
