/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrouchy <hrouchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:37:07 by hugz              #+#    #+#             */
/*   Updated: 2025/06/10 16:57:02 by hrouchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack_a(t_stack **stack, int nb)
{
	t_stack	*current;

	current = *stack;
	while (current)
	{
		if (current->value == nb)
			return (0);
		current = current->next;
	}
	return (1);
}

t_stack	*parse_arg(t_stack **stack_a, char *argv)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(argv, ' ');
	if (!(split))
		return (NULL);
	while (split[i])
	{
		if (!is_num(split[i]) || !add_fill_stack(stack_a, ft_atoi(split[i])))
		{
			ft_putstr_fd("error\n", 2);
			free_split(split);
			ft_lstclear(stack_a);
			return (NULL);
		}
		i++;
	}
	free_split(split);
	return (*stack_a);
}

int	parse_all_args(t_stack **stack_a, int argc, char **argv)
{
	int	i ;

	i = 1;
	while (i < argc)
	{
		if (!parse_arg(stack_a, argv[i]))
		{
			ft_lstclear(stack_a);
			return (0);
		}
		i++;
	}
	return (1);
}
