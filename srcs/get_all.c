/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugz <hugz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:20:30 by hugz              #+#    #+#             */
/*   Updated: 2025/06/07 17:04:10 by hugz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	*get_last(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	if (tmp == NULL)
		return (NULL);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

t_stack	*get_before_last(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	while (tmp->next && tmp->next->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

int	get_index(t_stack *stack, int value)
{
	t_stack	*current;
	int		index;

	current = stack;
	index = 0;
	while (current && current->value != value)
	{
		index++;
		current = current->next;
	}
	return (index);
}

int	find_lower_value(t_stack *stack)
{
	t_stack	*current;
	int		lower;

	current = stack;
	lower = 2147483647;
	while (current)
	{
		if (current->value < lower)
			lower = current->value;
		current = current->next;
	}
	return (lower);
}

int	get_total_cost(t_stack *stack_a, t_stack **stack_b)
{
	int		cost_a;
	int		cost_b = 0;
	t_stack	*target_b;

	cost_a = stack_a->cost;
	target_b = *stack_b;

	while (target_b && target_b->value != stack_a->target)
		target_b = target_b->next;

	if (!target_b)
	{
		//printf("⚠️  WARNING: Aucun target trouvé pour la value %d (target = %d)\n",
		//	stack_a->value, stack_a->target);
	}
	else
	{
		cost_b = target_b->cost;
	}

	return combine_costs(cost_a, cost_b);
}
