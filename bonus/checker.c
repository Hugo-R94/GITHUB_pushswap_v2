/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrouchy <hrouchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:13:19 by hrouchy           #+#    #+#             */
/*   Updated: 2025/06/10 16:57:52 by hrouchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"
#include <stdio.h>

int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	if (!current)
	{
		return (0);
	}
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	check_move(char *input, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(input, "sa\n") == 0)
		swap(*stack_a);
	else if (ft_strcmp(input, "sb\n") == 0)
		swap(*stack_b);
	else if (ft_strcmp(input, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(input, "pa\n") == 0)
		push(stack_b, stack_a);
	else if (ft_strcmp(input, "pb\n") == 0)
		push(stack_a, stack_b);
	else if (ft_strcmp(input, "ra\n") == 0)
		rotate(stack_a);
	else if (ft_strcmp(input, "rb\n") == 0)
		rotate(stack_b);
	else if (ft_strcmp(input, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(input, "rra\n") == 0)
		reverse_rotate(stack_a);
	else if (ft_strcmp(input, "rrb\n") == 0)
		reverse_rotate(stack_b);
	else if (ft_strcmp(input, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	read_input(t_stack **stack_a, t_stack **stack_b)
{
	char	*buf;

	buf = get_next_line(0);
	while (buf)
	{
		if (!check_move(buf, stack_a, stack_b))
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		free (buf);
		buf = get_next_line(0);
	}
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
	read_input(&stack_a, &stack_b);
	if (is_sorted(stack_a) == 1 && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
