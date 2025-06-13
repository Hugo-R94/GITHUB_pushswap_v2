/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrouchy <hrouchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:03:19 by hrouchy           #+#    #+#             */
/*   Updated: 2025/06/11 11:20:33 by hrouchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
//swap : Intervertit les 2 premiers éléments au sommet de la pile.
//Ne fait rien s’il n’y en a qu’un ou aucun.
void	swap(t_stack *stack)
{
	int	tmp;

	if (!stack)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

//applique swap sur les 2 piles.
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
}
