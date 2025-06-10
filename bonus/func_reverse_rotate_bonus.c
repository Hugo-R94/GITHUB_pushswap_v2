/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_reverse_rotate_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrouchy <hrouchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:19:41 by hrouchy           #+#    #+#             */
/*   Updated: 2025/06/10 16:20:10 by hrouchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../headers/checker.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*before_last;
	t_stack	*head;

	head = *stack;
	last = get_last(head);
	before_last = get_before_last(head);
	before_last->next = NULL;
	last->next = head;
	*stack = last;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
