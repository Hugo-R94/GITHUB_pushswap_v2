/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugz <hugz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:13:23 by hrouchy           #+#    #+#             */
/*   Updated: 2025/06/08 22:43:01 by hugz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"


// void	ft_lstclear(t_stack **lst)
// {
// 	t_stack	*tmp;

// 	if (!*lst)
// 		return ;
// 	while (*lst)
// void	ft_lstclear(t_stack **lst)
// {
// 	t_stack	*tmp;

// 	if (!*lst)
// 		return ;
// 	while (*lst)
// 	{
// 		tmp = (*lst)->next;
// 		if (lst)
// 		{
// 			free(lst);
// 		}
// 		*lst = tmp;
// 	}
// 	//*lst = 0;
// }

void	push(t_stack *stack, int value)
{
	t_stack *new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return;
	new_node->value = value;
	new_node->next = stack;
	stack = new_node;
}


t_stack* create_stack(int *array,int size)
{
	int index;
	
	index = size - 1;
	t_stack* head = NULL;
	while (index >= 0)
	{
		t_stack* new_list = malloc(sizeof(t_stack));
		new_list->value = array[index--];
		new_list->next = head;
		head = new_list;
	}
	return (head);	
}

// void	print_stack(t_stack* stack_a, t_stack* stack_b)
// {	
// 	printf("\033[0;32m%-10s\033[0m","stack_a");
// 	printf(" || ");
// 	printf("\033[0;31m%10s\033[0m\n\n","stack_b");
// 	while (stack_a || stack_b)
// 	{
// 		if (stack_a)
// 		{
// 			printf("(%i)\033[0;32m%-5i\033[0m/\x1B[33m%-10i\033[0m-/%-5i /t_cost = %-5i",stack_a->index, stack_a->value,stack_a->cost,stack_a->target,stack_a->total_cost);
// 			stack_a = stack_a->next;
// 		}
// 		else
// 			printf("\033[0;32m%-13s\033[0m   ","//");
// 		printf(" || ");
// 		if (stack_b)
// 		{
// 			printf("\x1B[33m%10i\033[0m/\033[0;31m%i\033[0m(%i)\n",stack_b->cost,stack_b->value, stack_b->index);
// 			stack_b = stack_b->next;
// 		}
// 		else
// 			printf("\033[0;31m%10s\033[0m   \n","//");
// 	}
// 	return ;
	
// }

#include <stdio.h>
#include "push_swap.h" // si tu as un fichier contenant la déclaration de t_stack

void print_stack(t_stack* stack_a, t_stack* stack_b)
{
    printf("+------------------------------+------------------------------+\n");
    printf("|         Stack A             |           Stack B            |\n");
    printf("|-----------------------------|------------------------------|\n");
    printf("| Idx | Val   | Cost | Tgt |Tot| Cost |  Val | Idx |\n");
    printf("+------------------------------+------------------------------+\n");

    while (stack_a || stack_b)
    {
        // Partie gauche : Stack A
        if (stack_a)
        {
            printf("| %3d | %5d | %4d | %3d | %3d ",
                   stack_a->index,
                   stack_a->value,
                   stack_a->cost,
                   stack_a->target,
                   stack_a->total_cost);
            stack_a = stack_a->next;
        }
        else
        {
            printf("|                            ");
        }

        // Partie droite : Stack B
        if (stack_b)
        {
            printf("| %4d | %5d | %3d |\n",
                   stack_b->cost,
                   stack_b->value,
                   stack_b->index);
            stack_b = stack_b->next;
        }
        else
        {
            printf("|                          |\n");
        }
    }

    printf("+------------------------------+------------------------------+\n");
}

// Déclaration des types de fonctions
typedef void (*t_func_1)(t_stack **);
typedef void (*t_func_2)(t_stack **, t_stack **);

// La fonction wrapper
void do_and_print(
	t_stack **a,
	t_stack **b,
	void *func,
	char stack_id // 1 pour f(t_stack **), 2 pour f(t_stack **, t_stack **)
)
{
	//print_stack(*a, *b);
	if (stack_id == 'a')
		((t_func_1)func)(a);
	else if (stack_id == 'b')
		((t_func_1)func)(b);
	else
		((t_func_2)func)(a, b);
	set_all(a,b);
	//print_stack(*a, *b);
}

// int main() {
//     int array1[4] = {10, 22, 33, 44};
//     int array2[12] = {77, 88, 99, 444, 66, 56 ,78 ,74 ,12 ,47, 5,55};

//     t_stack* stack_a = create_stack(array1,5);
//     t_stack* stack_b = create_stack(array2,12);

//     print_pile(stack_a, stack_b);
// 	// ft_lstclear(&stack_a);
// 	// ft_lstclear(&stack_b);
//     // Libération mémoire recommandée ici

//     return 0;
// }