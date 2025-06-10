/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrouchy <hrouchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:38:36 by hugz              #+#    #+#             */
/*   Updated: 2025/06/09 12:32:11 by hrouchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	do_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	nb_move_a;
	int	nb_move_b;
	int	lower_total;

	set_all(stack_a, stack_b);
	lower_total = find_lower_total(stack_a);
	nb_move_a = get_nb_move_a(stack_a, lower_total);
	nb_move_b = get_nb_move_b(stack_a, stack_b, lower_total);
	do_sort_moves(stack_a, stack_b, &nb_move_a, &nb_move_b);
	pb(stack_a, stack_b);
}

void	do_sort_moves(t_stack **a, t_stack **b, int *nb_move_a, int *nb_move_b)
{
	while (*nb_move_a != 0 || *nb_move_b != 0)
	{
		if (*nb_move_a > 0 && *nb_move_b > 0)
		{
			rr(a, b);
			(*nb_move_a)--;
			(*nb_move_b)--;
		}
		else if (*nb_move_a < 0 && *nb_move_b < 0)
		{
			rrr(a, b);
			(*nb_move_a)++;
			(*nb_move_b)++;
		}
		else if (*nb_move_a != 0)
			*nb_move_a = do_sort_one(a, b, *nb_move_a, 'a');
		else if (*nb_move_b != 0)
			*nb_move_b = do_sort_one(a, b, *nb_move_b, 'b');
	}
}

static int	get_max_cost(t_stack *stack, int *max_value)
{
	int		pos;
	int		max_pos;
	int		size;

	pos = 0;
	max_pos = 0;
	size = 0;
	*max_value = stack->value;
	while (stack)
	{
		if (stack->value > *max_value)
		{
			*max_value = stack->value;
			max_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	size = pos;
	if (max_pos <= size / 2)
		return (max_pos);
	else
		return (max_pos - size);
}

void	rotate_max_to_top(t_stack **stack_b)
{
	t_stack	*current;
	int		max_value;
	int		cost;

	if (!stack_b || !*stack_b)
		return ;
	current = *stack_b;
	cost = get_max_cost(current, &max_value);
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

void	push_back_b(t_stack **stack_a, t_stack **stack_b)
{
	int	rotations;
	int	size_a;

	rotations = 0;
	size_a = ft_lstsize(*stack_a);
	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
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
