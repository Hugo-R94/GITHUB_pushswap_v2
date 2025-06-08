/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugz <hugz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:26:03 by hrouchy           #+#    #+#             */
/*   Updated: 2025/06/08 12:34:49 by hugz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct s_stack
{
	int				cost;
	int				value;
	int				index;
	int				target;
	int 			total_cost;
	struct s_stack* next;
}	t_stack;

int     add_fill_stack(t_stack **stack, int nb);
int     check_stack_a(t_stack **stack, int nb);
t_stack *create_node(int nb);
void    do_sort(t_stack **stack_a, t_stack **stack_b);
int     do_sort_one(t_stack **stack, int nb_move);
int     find_lower_value(t_stack *stack);
int     ft_atoi(const char *nptr);
void    ft_basecase(t_stack **stack_a, t_stack **stack_b);
void    ft_lstadd_back(t_stack **lst, t_stack *new);
void    ft_lstclear(t_stack **lst);
int     ft_lstsize(t_stack *lst);
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char *s, int fd);
void    ft_sort_2(t_stack **stack);
void    ft_sort_3(t_stack **stack);
char    **ft_split(char *str, char c);
t_stack *get_before_last(t_stack *lst);
int     get_index(t_stack *stack, int value);
t_stack *get_last(t_stack *lst);
int     get_total_cost(t_stack *stack_a, t_stack **stack_b);
int     is_num(char *number);
int     main(int argc, char **argv);
void    pa(t_stack **stack_a, t_stack **stack_b);
t_stack *parse_arg(t_stack **stack_a, char *argv);
void    pb(t_stack **stack_a, t_stack **stack_b);
void    ra(t_stack **stack_a);
void    rb(t_stack **stack_b);
void    reverse_rotate(t_stack **stack);
void    rotate(t_stack **stack);
void    rr(t_stack **stack_a, t_stack **stack_b);
void    rra(t_stack **stack);
void    rrb(t_stack **stack);
void    rrr(t_stack **stack_a, t_stack **stack_b);
void    sa(t_stack **stack_a);
void    sb(t_stack **stack_b);
void    set_all(t_stack **stack_a, t_stack **stack_b);
void    set_all_index(t_stack **list);
void    set_cost(t_stack **list);
void    set_target_index(t_stack **stack_a, t_stack **stack_b);
void    set_total_cost(t_stack **stack_a, t_stack **stack_b);
void    sort_base(t_stack **stack_a, t_stack **stack_b);
void    sort_long(t_stack **stack_a, t_stack **stack_b);
void    sort_to_5(t_stack **stack_a, t_stack **stack_b);
void    ss(t_stack **stack_a, t_stack **stack_b);
void    swap(t_stack *stack);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		combine_costs(int a, int b);
void	print_stack(t_stack* stack_a, t_stack* stack_b);
int		get_nb_move(t_stack **stack,int lower_total);

#endif
