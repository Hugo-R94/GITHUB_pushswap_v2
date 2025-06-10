/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrouchy <hrouchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:04:53 by hrouchy           #+#    #+#             */
/*   Updated: 2025/06/09 11:48:56 by hrouchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_lower_total(t_stack **stack)
{
	t_stack	*current;
	int		lower_total;

	if (!*stack)
		return (0);
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
	return (lower_total);
}

int	get_nb_move_a(t_stack **stack, int lower_total)
{
	t_stack	*current;

	if (!stack || !*stack)
		return (0);
	current = *stack;
	while (current)
	{
		if (current->total_cost == lower_total)
		{
			return (current->cost);
		}
		current = current->next;
	}
	return (0);
}

int	get_nb_move_b(t_stack **stack_a, t_stack **stack_b, int lower_total)
{
	t_stack	*node_a;
	t_stack	*target_b;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return (0);
	node_a = *stack_a;
	while (node_a && node_a->total_cost != lower_total)
		node_a = node_a->next;
	if (!node_a || !node_a->target)
		return (0);
	target_b = *stack_b;
	while (target_b)
	{
		if (target_b->value == node_a->target)
			return (target_b->cost);
		target_b = target_b->next;
	}
	return (0);
}

int	do_sort_one(t_stack **stack_a, t_stack **stack_b, int nb_move, char id)
{
	while (nb_move != 0)
	{
		if (nb_move < 0)
		{
			reverse_rotate_x(stack_a, stack_b, id);
			nb_move++;
		}
		else
		{
			rotate_x(stack_a, stack_b, id);
			nb_move--;
		}
	}
	return (nb_move);
}
