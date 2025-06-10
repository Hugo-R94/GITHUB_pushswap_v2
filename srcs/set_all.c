/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrouchy <hrouchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:16:07 by hugz              #+#    #+#             */
/*   Updated: 2025/06/10 16:45:00 by hrouchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	set_cost(t_stack **list)
{
	t_stack	*current;
	int		list_size;

	list_size = ft_lstsize(*list);
	current = *list;
	while (current)
	{
		if (current->index > list_size / 2 && list_size > 3)
			current->cost = current->index - list_size;
		else
			current->cost = current->index;
		current = current->next;
	}
}

void	set_target_index(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;

	current_a = *stack_a;
	while (current_a)
	{
		current_a->target = find_best_target(*stack_b, current_a->value);
		current_a = current_a->next;
	}
}

void	set_all_index(t_stack **list)
{
	int		index;
	t_stack	*current;

	index = 0;
	current = *list;
	while (current)
	{
		current->index = index;
		index++;
		current = current->next;
	}
}

void	set_total_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;

	current = *stack_a;
	while (current)
	{
		current->total_cost = get_total_cost(current, stack_b);
		current = current->next;
	}
}

void	set_all(t_stack **stack_a, t_stack **stack_b)
{
	set_all_index(stack_a);
	set_all_index(stack_b);
	set_cost(stack_a);
	set_cost(stack_b);
	set_target_index(stack_a, stack_b);
	set_total_cost(stack_a, stack_b);
	set_total_cost(stack_b, stack_a);
}
