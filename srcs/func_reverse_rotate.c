/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrouchy <hrouchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:19:41 by hrouchy           #+#    #+#             */
/*   Updated: 2025/06/09 12:37:20 by hrouchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

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

void	rra(t_stack **stack)
{
	reverse_rotate(stack);
	ft_putstr("rra\n");
}

void	rrb(t_stack **stack)
{
	reverse_rotate(stack);
	ft_putstr("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr("rrr\n");
}

void	reverse_rotate_x(t_stack **stack_a, t_stack **stack_b, char id)
{
	if (id == 'a')
		rra(stack_a);
	else if (id == 'b')
		rrb(stack_b);
}
