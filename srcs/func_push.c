/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugz <hugz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:00:12 by hrouchy           #+#    #+#             */
/*   Updated: 2025/06/06 23:31:03 by hugz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//mets le premier element de stackb sur stacka
void pa(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;

    if (!*stack_b)
        return;
    tmp = *stack_b;               // on garde l’élément à transférer
    *stack_b = (*stack_b)->next;  // on avance dans stack_2
    tmp->next = *stack_a;         // on lie tmp à l’ancien sommet de stack_1
    *stack_a = tmp;               // tmp devient le nouveau sommet de stack_1
	ft_putstr("pa\n");
}
//mets le premier element de stack1 sur stack2
void pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;

    if (!*stack_a)
        return;
    
    tmp = *stack_a;               // on garde l’élément à transférer
    *stack_a = (*stack_a)->next;  // on avance dans stack_2
    tmp->next = *stack_b;         // on lie tmp à l’ancien sommet de stack_1
    *stack_b = tmp;               // tmp devient le nouveau sommet de stack_1
	ft_putstr("pb\n");
}