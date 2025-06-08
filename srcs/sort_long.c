/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugz <hugz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:38:36 by hugz              #+#    #+#             */
/*   Updated: 2025/06/08 22:50:03 by hugz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	find_lower_total(t_stack **stack)
{
	t_stack *current;
	int lower_total;

    if (!*stack)
        return 0;

    current = *stack;
    lower_total = 2147483647;
    while (current)
    {
        if (current->total_cost < lower_total)
		{
            lower_total = current->total_cost;
		}
        current = current->next;
    }
    return lower_total;
}


#include <stdio.h>  // Pour printf

int get_nb_move_a(t_stack **stack, int lower_total)
{
    t_stack *current;

    if (!stack || !*stack)
    {
        return 0;
    }

    current = *stack;
    while (current)
    {
        if (current->total_cost == lower_total)
        {
            return current->cost;
        }

        current = current->next;
    }
    return 0; // Ou -1 si tu veux signaler une erreur
}




int get_nb_move_b(t_stack **stack_a, t_stack **stack_b, int lower_total)
{
	t_stack *node_a;
	t_stack *target_b;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return 0;
	node_a = *stack_a;
	while (node_a && node_a->total_cost != lower_total)
		node_a = node_a->next;

	if (!node_a || !node_a->target)
		return 0;
	target_b = *stack_b;
	while (target_b)
	{
		if (target_b->value == node_a->target)
			return target_b->cost;
		target_b = target_b->next;
	}
	return 0;
}


int do_sort_one(t_stack **stack, int nb_move)
{
	while (nb_move != 0)
	{
		if (nb_move < 0)
		{
			rrb(stack);
			nb_move++;
		}
		else
		{
			rb(stack);
			nb_move--;
		}
	}
	return(nb_move);
}


void	do_sort(t_stack **stack_a, t_stack **stack_b)
{
	int nb_move_a;
	int nb_move_b;
	int lower_total;

	set_all(stack_a, stack_b);
	lower_total = find_lower_total(stack_a); // Si tu gardes cette fonction
	nb_move_a = get_nb_move_a(stack_a, lower_total);
	nb_move_b = get_nb_move_b(stack_a, stack_b, lower_total);
	while (nb_move_a != 0 || nb_move_b != 0)
{
	if (nb_move_a > 0 && nb_move_b > 0)
	{
		rr(stack_a, stack_b);
		nb_move_a--;
		nb_move_b--;
	}
	else if (nb_move_a < 0 && nb_move_b < 0)
	{
		rrr(stack_a, stack_b);
		nb_move_a++;
		nb_move_b++;
	}
	else if (nb_move_a > 0)
		nb_move_a = do_sort_one(stack_a, nb_move_a);
	else if (nb_move_a < 0)
		nb_move_a = do_sort_one(stack_a, nb_move_a);
	else if (nb_move_b > 0)
		nb_move_b = do_sort_one(stack_b, nb_move_b);
	else if (nb_move_b < 0)
		nb_move_b = do_sort_one(stack_b, nb_move_b);
}
	pb(stack_a, stack_b);
}

void rotate_max_to_top(t_stack **stack_b)
{
    t_stack *current = *stack_b;
    int max_value;
    int cost = 0;
    int pos = 0;
    int max_pos = 0;
    int size = 0;

    if (!stack_b || !*stack_b)
        return;

    max_value = current->value;
    while (current)
    {
        if (current->value > max_value)
        {
            max_value = current->value;
            max_pos = pos;
        }
        current = current->next;
        pos++;
    }
    size = pos;

    if (max_pos <= size / 2)
        cost = max_pos;
    else
        cost = max_pos - size;

    while (cost < 0)
    {
        rrb(stack_b);
        cost++;
    }
    while (cost > 0)
    {
        rb(stack_b);
        cost--;
    }
}



void push_back_b(t_stack **stack_a, t_stack **stack_b)
{
    int rotations = 0;
    int size_a = ft_lstsize(*stack_a);

    if (!stack_a || !*stack_a || !stack_b || !*stack_b)
        return;

    while ((*stack_a)->value <= (*stack_b)->value && rotations < size_a)
    {
        ra(stack_a);
        rotations++;
    }

    pa(stack_a, stack_b);

    while (rotations > 0)
    {
        rra(stack_a);
        rotations--;
    }
}

void final_merge_simple(t_stack **a, t_stack **b)
{
	int count = 0;
    int last_val;

    while (*b)
    {
        last_val = get_last(*a)->value;

        while (*b && (*b)->value > last_val)
        {
            pa(a, b);
            last_val = get_last(*a)->value;  // update après chaque push
        }

        if (*b )
		{
            rra(a);
			count++;
		}
		if (count >= 4)
			exit(EXIT_FAILURE);
    }
}


void	final_merge(t_stack **a, t_stack **b)
{
	int rotations = 0;
	int last;

	if (*b && (*b)->value > get_last(*a)->value)
		pa(a, b);
	while (*b && rotations < 3)
	{
		int top = (*a)->value;
		last = get_last(*a)->value;
		while (*b && (*b)->value > last && (*b)->value < top)
			pa(a, b);
		if (*b)
		{
			rra(a);
			rotations++;
		}
	}
	while (*b)
		pa(a, b);
	last = get_last(*a)->value;
	if((*a)->value > last)
		rra(a);
}



void sort_long(t_stack **a, t_stack **b)
{
	set_all(a, b);
	pb(a, b);
	pb(a, b);
	set_all(a, b);
	if ((*b)->value < (*b)->next->value)
		sb(b);
	while (ft_lstsize(*a) > 3)
	{
		set_all(a, b);
		do_sort(a, b);
	}
	ft_sort_3(a);
	rotate_max_to_top(b);
	final_merge(a, b);	
}