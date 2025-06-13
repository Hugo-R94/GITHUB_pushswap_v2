/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrouchy <hrouchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:44:42 by arommers          #+#    #+#             */
/*   Updated: 2025/06/13 15:33:38 by hrouchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include "push_swap.h"
# include "get_next_line.h"

int		is_sorted(t_stack *stack);
int		ft_strcmp(char *s1, char *s2);
int		check_move(char *input, t_stack **stack_a, t_stack **stack_b);
void	read_input(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	swap(t_stack *stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
int		check_stack_a(t_stack **stack, int nb);
t_stack	*parse_arg(t_stack **stack_a, char *argv);
int		parse_all_args(t_stack **stack_a, int argc, char **argv);
void	push(t_stack **stack_from, t_stack **stack_to);

#endif
