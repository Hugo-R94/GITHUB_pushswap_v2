/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrouchy <hrouchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:26:03 by hrouchy           #+#    #+#             */
/*   Updated: 2025/06/10 16:59:15 by hrouchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

typedef struct s_stack
{
	int				cost;
	int				value;
	int				index;
	int				target;
	int				total_cost;
	struct s_stack	*next;
}	t_stack;

int		add_fill_stack(t_stack **stack, int nb);
int		check_stack_a(t_stack **stack, int nb);
t_stack	*create_node(int nb);
t_stack	*get_before_last(t_stack *lst);
t_stack	*get_last(t_stack *lst);
t_stack	*parse_arg(t_stack **stack_a, char *argv);

void	do_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_basecase(t_stack **stack_a, t_stack **stack_b);
void	handle_merge_rotation(t_stack **a, t_stack **b, int *rot);
void	print_stack(t_stack *stack_a, t_stack *stack_b);
void	free_split(char **split);

int		find_best_target(t_stack *stack_b, int value);
int		find_lower_total(t_stack **stack);
int		find_lower_value(t_stack *stack);
int		get_index(t_stack *stack, int value);
int		get_nb_move(t_stack **stack, int lower_total);
int		get_nb_move_a(t_stack **stack, int lower_total);
int		get_nb_move_b(t_stack **a, t_stack **b, int lower_total);
int		get_total_cost(t_stack *stack_a, t_stack **stack_b);

int		ft_atoi(const char *nptr);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar(char c);
void	ft_putstr(char *str);
char	**ft_split(char *str, char c);

int		combine_costs(int a, int b);
int		is_num(char *number);
int		parse_all_args(t_stack **stack_a, int argc, char **argv);
int		ft_lstsize(t_stack *lst);

void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **lst);

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	swap(t_stack *stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	rotate_x(t_stack **a, t_stack **b, char id);
void	reverse_rotate_x(t_stack **a, t_stack **b, char id);

void	set_all(t_stack **stack_a, t_stack **stack_b);
void	set_all_index(t_stack **list);
void	set_cost(t_stack **list);
void	set_target_index(t_stack **a, t_stack **b);
void	set_total_cost(t_stack **a, t_stack **b);
void	rotate_max_to_top(t_stack **stack_b);

void	sort_base(t_stack **stack_a, t_stack **stack_b);
void	sort_long(t_stack **stack_a, t_stack **stack_b);
void	sort_to_5(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_2(t_stack **stack);
void	ft_sort_3(t_stack **stack);

int		do_sort_one(t_stack **a, t_stack **b, int nb_move, char id);
void	do_sort_moves(t_stack **a, t_stack **b, int *nb_a, int *nb_b);

#endif
