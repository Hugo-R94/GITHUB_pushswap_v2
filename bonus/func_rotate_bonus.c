/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rotate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrouchy <hrouchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:19:11 by hrouchy           #+#    #+#             */
/*   Updated: 2025/06/10 16:21:01 by hrouchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../headers/checker.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *stack;
	*stack = (*stack)->next;
	last = get_last(*stack);
	tmp->next = NULL;
	last->next = tmp;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
