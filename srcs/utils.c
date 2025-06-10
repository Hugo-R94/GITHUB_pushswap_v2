/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrouchy <hrouchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:12:53 by hrouchy           #+#    #+#             */
/*   Updated: 2025/06/10 16:53:09 by hrouchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_best_target(t_stack *stack_b, int value)
{
	t_stack	*current_b;
	t_stack	*best_lower;
	t_stack	*max_node;

	current_b = stack_b;
	best_lower = NULL;
	max_node = NULL;
	while (current_b)
	{
		if (!max_node || current_b->value > max_node->value)
			max_node = current_b;
		if (current_b->value < value)
		{
			if (!best_lower || current_b->value > best_lower->value)
				best_lower = current_b;
		}
		current_b = current_b->next;
	}
	if (best_lower)
		return (best_lower->value);
	else if (max_node)
		return (max_node->value);
	else
		return (-1);
}

// void	final_merge(t_stack **a, t_stack **b)
// {
// 	int	rotations;
// 	int	last;
// 	int	top;

// 	rotations = 0;
// 	if (*b && (*b)->value > get_last(*a)->value)
// 		pa(a, b);
// 	while (*b && rotations < 3)
// 	{
// 		top = (*a)->value;
// 		last = get_last(*a)->value;
// 		while (*b && (*b)->value > last && (*b)->value < top)
// 			pa(a, b);
// 		if (*b)
// 		{
// 			rra(a);
// 			rotations++;
// 		}
// 	}
// 	while (*b)
// 		pa(a, b);
// 	last = get_last(*a)->value;
// 	while ((*a)->value > last)
// 	{
// 		rra(a);
// 		last = get_last(*a)->value;
// 	}
// }
// Partie principale
void	final_merge(t_stack **a, t_stack **b)
{
	int	rotations;
	int	last;

	rotations = 0;
	if (*b && (*b)->value > get_last(*a)->value)
		pa(a, b);
	while (*b && rotations < 3)
	{
		handle_merge_rotation(a, b, &rotations);
	}
	while (*b)
		pa(a, b);
	last = get_last(*a)->value;
	while ((*a)->value > last)
	{
		rra(a);
		last = get_last(*a)->value;
	}
}

// Partie extraite
void	handle_merge_rotation(t_stack **a, t_stack **b, int *rotations)
{
	int	top;
	int	last;

	top = (*a)->value;
	last = get_last(*a)->value;
	while (*b && (*b)->value > last && (*b)->value < top)
		pa(a, b);
	if (*b)
	{
		rra(a);
		(*rotations)++;
	}
}

void	sort_long(t_stack **a, t_stack **b)
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
	set_all_index(a);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
