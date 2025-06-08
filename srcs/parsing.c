/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugz <hugz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:37:07 by hugz              #+#    #+#             */
/*   Updated: 2025/06/06 22:37:34 by hugz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_stack_a(t_stack **stack,int nb)
{
	t_stack *current;
	current = *stack;
	while (current)
		{
			if (current->value == nb)
				return (0);
			current = current->next;
		}
	return (1);
}

t_stack *parse_arg(t_stack **stack_a, char *argv)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(argv, ' ');
	if (!split)
		return NULL;
	while (split[i])
	{
		if (!is_num(split[i]))
		{
			ft_putstr_fd("error\n", 2);
			return NULL;
		}
		if (add_fill_stack(stack_a, ft_atoi(split[i])) == 0)
		{
			ft_putstr_fd("error\n", 2);
			return NULL;
		}
		i++;
	}
	while (i >= 0 )
		free(split[i--]);
	free(split);
	return (*stack_a);
}