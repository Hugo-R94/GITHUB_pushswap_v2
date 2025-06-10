/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrouchy <hrouchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:33:36 by hrouchy           #+#    #+#             */
/*   Updated: 2025/06/10 16:25:26 by hrouchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*get_last(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	if (tmp == NULL)
		return (NULL);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

t_stack	*get_before_last(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	while (tmp->next && tmp->next->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
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
