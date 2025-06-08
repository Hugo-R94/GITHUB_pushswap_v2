/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugz <hugz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:52:52 by hrouchy           #+#    #+#             */
/*   Updated: 2025/06/07 00:34:52 by hugz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_error(void)
{
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}

void	ft_sort_2(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	if (current->value > current->next->value)
		sa(stack);
}

void	ft_sort_3(t_stack **stack)
{
	int	a = (*stack)->value;
	int	b = (*stack)->next->value;
	int	c = (*stack)->next->next->value;

	if (a < b && b < c)
		return ;
	else if (a < c && c < b)
	{
		rra(stack);
		sa(stack);
	}
	else if (b < a && a < c)
		sa(stack);
	else if (c < a && a < b)
		rra(stack);
	else if (b < c && c < a)
		ra(stack);
	else if (c < b && b < a)
	{
		sa(stack);
		rra(stack);
	}
	//exit(EXIT_SUCCESS);
}

void sort_to_5(t_stack **stack_a, t_stack **stack_b)
{
	int min;
	while (ft_lstsize(*stack_a) > 3)
	{
		min = find_lower_value(*stack_a);
		while ((*stack_a)->value != min)
		{
			if (get_index(*stack_a,min) <= ft_lstsize(*stack_a) / 2)
			{
				ra(stack_a);
			}
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	ft_sort_3(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
	//print_stack(*stack_a, *stack_b);
}

void	sort_base(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) == 0)
		ft_error();
	if (ft_lstsize(*stack_a) == 1)
		exit(EXIT_SUCCESS);
	if (ft_lstsize(*stack_a) == 2)
		ft_sort_2(stack_a);
	if (ft_lstsize(*stack_a) == 3)
		ft_sort_3(stack_a);
	if (ft_lstsize(*stack_a) == 4 || ft_lstsize(*stack_a) == 5)
		sort_to_5(stack_a,stack_b);
}
