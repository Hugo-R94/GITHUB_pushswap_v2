/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrouchy <hrouchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:16:34 by hrouchy           #+#    #+#             */
/*   Updated: 2025/06/13 15:31:25 by hrouchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	is_sorted(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	if (!current)
	{
		exit(EXIT_SUCCESS);
	}
	while (current->next)
	{
		if (current->value > current->next->value)
			return ;
		current = current->next;
	}
	exit(EXIT_SUCCESS);
}

int	is_num(char *number)
{
	int	index;

	index = 0;
	while (number[index])
	{
		if ((number[index] >= '0' && number[index] <= '9')
			|| number[index] == ' ' || number[index] == '-')
		{
			index++;
		}
		else
			return (0);
	}
	return (1);
}

//fonctionne avec get_total_cost
int	combine_costs(int a, int b)
{
	if (a >= 0 && b >= 0)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	else if (a < 0 && b < 0)
	{
		if (-a > -b)
			return (-a);
		else
			return (-b);
	}
	else
		return (abs(a) + abs(b));
}

void	ft_basecase(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) == 0)
		exit (EXIT_SUCCESS);
	if (ft_lstsize(*stack_a) == 1)
		exit (EXIT_SUCCESS);
	if (ft_lstsize(*stack_a) == 2)
		ft_sort_2 (stack_a);
	if (ft_lstsize(*stack_a) == 3)
		ft_sort_3 (stack_a);
	if (ft_lstsize(*stack_a) == 4 || ft_lstsize(*stack_a) == 5)
		sort_to_5 (stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!parse_all_args(&stack_a, argc, argv))
		return (1);
	is_sorted(stack_a);
	if (ft_lstsize(stack_a) <= 5)
		ft_basecase(&stack_a, &stack_b);
	else
		sort_long(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (0);
}
