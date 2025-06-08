/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugz <hugz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:16:07 by hugz              #+#    #+#             */
/*   Updated: 2025/06/08 22:36:51 by hugz             ###   ########.fr       */
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

		//printf("Valeur %d => index %d, cost %d\n", current->value, current->index, current->cost); // <== AJOUTE ÇA
		current = current->next;
	}
}


#include <stdio.h>

// Met à jour le target de chaque élément de stack_a : 
// la valeur dans stack_b qui est la plus proche et inférieure à current->value,
// ou la plus petite valeur de stack_b si aucune inférieure n'existe.
void set_target_index(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current_a;
    t_stack *current_b;
    t_stack *best_lower;
    t_stack *max_node;

    current_a = *stack_a;
    while (current_a)
    {
        best_lower = NULL;
        max_node = NULL;
        current_b = *stack_b;

        while (current_b)
        {
            if (!max_node || current_b->value > max_node->value)
                max_node = current_b;

            if (current_b->value < current_a->value)
            {
                if (!best_lower || current_b->value > best_lower->value)
                    best_lower = current_b;
            }

            current_b = current_b->next;
        }

        if (best_lower)
            current_a->target = best_lower->value;
        else if (max_node)
            current_a->target = max_node->value;
        else
            current_a->target = -1; // stack_b vide

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

void set_total_cost(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current = *stack_a;

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
	set_cost(stack_a);     // ici
	set_cost(stack_b);     // ici
	set_target_index(stack_a, stack_b);
	set_total_cost(stack_a, stack_b);  
    set_total_cost(stack_b, stack_a); // dépend de ce qui est fait avant
}
