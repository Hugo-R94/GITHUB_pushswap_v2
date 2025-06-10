/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrouchy <hrouchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:31:12 by hugz              #+#    #+#             */
/*   Updated: 2025/06/10 14:33:52 by hrouchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_lstsize(t_stack *lst)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}

t_stack	*create_node(int nb)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = nb;
	node->next = NULL;
	return (node);
}

int	add_fill_stack(t_stack **stack, int nb)
{
	t_stack	*new_node;

	if (!check_stack_a(stack, nb))
		return (0);
	new_node = create_node(nb);
	if (!new_node)
		return (0);
	ft_lstadd_back(stack, new_node);
	return (1);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
