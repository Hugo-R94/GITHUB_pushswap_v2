/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_push_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrouchy <hrouchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:00:12 by hrouchy           #+#    #+#             */
/*   Updated: 2025/06/10 16:19:43 by hrouchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
}

//mets le premier element de stack1 sur stack2
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
}

void	push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*tmp;

	if (!*stack_from)
		return ;
	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	tmp->next = *stack_to;
	*stack_to = tmp;
}
