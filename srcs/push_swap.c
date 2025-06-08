/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugz <hugz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:16:34 by hrouchy           #+#    #+#             */
/*   Updated: 2025/06/08 22:42:11 by hugz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	is_num(char *number)
{
	int	index;

	index = 0;
	while (number[index])
	{
		if ((number[index] >= '0' && number[index] <= '9') || number[index] == ' ' || number[index] == '-')
		{
			index++;
		}
		else
			return (0);
	}
	return (1);
}
//fonctionne avec get_total_cost
int combine_costs(int a, int b)
{
	if (a >= 0 && b >= 0)
	{
		// rotations vers le haut : on fait des rr
		if (a > b)
			return a;
		else
			return b;
	}
	else if (a < 0 && b < 0)
	{
		// rotations vers le bas : on fait des rrr
		if (-a > -b)
			return -a;
		else
			return -b;
	}
	else
		return (abs(a) + abs(b));
}
void	ft_basecase(t_stack **stack_a, t_stack **stack_b)
{
	if(ft_lstsize(*stack_a) == 0)
		exit(EXIT_SUCCESS);
	//ft_error();
	if(ft_lstsize(*stack_a) == 1)
		exit(EXIT_SUCCESS);
	if(ft_lstsize(*stack_a) == 2)
		ft_sort_2(stack_a);
	if(ft_lstsize(*stack_a) == 3)
		ft_sort_3(stack_a);
	if (ft_lstsize(*stack_a) == 4 || ft_lstsize(*stack_a) == 5)
		sort_to_5(stack_a, stack_b);
	
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int 	i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);

	while (i < argc)
	{
		if (!parse_arg(&stack_a, argv[i]))
		{
			ft_lstclear(&stack_a);
			free(stack_a);
			return (1);
		}
		i++;
	}
	if (ft_lstsize(stack_a) <= 5)
		ft_basecase(&stack_a, &stack_b);
	else
		sort_long(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	ft_lstclear(&stack_a);
	return (0);
}
