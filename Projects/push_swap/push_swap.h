/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:20:15 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/19 04:10:38 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libraries/Libft/libft.h"
# include "libraries/ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
#include <limits.h>

//doubly linked list
typedef struct s_stack {
	
	int	data;
	int	index;
	int cost;
	int opnum;
	struct s_stack	*neighbor;
	struct s_stack *prev;
	struct s_stack *next;
}	t_stack;

//push_swap.c
void print_stack(t_stack *stack); //-to delete

//list_prep.c
t_stack *pop_stack(t_stack *a_stack, int argc, char **argv);
t_stack *pop_stack_string(char **argv, t_stack *a_stack);
t_stack	*ft_lstnew_ps(int	content);
void	ft_lstadd_back_ps(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast_ps(t_stack *lst);

//check.c
int check_sort(t_stack *a_stack);
int	ft_lstsize_ps(t_stack *lst);
int datacmp(t_stack *stack_a, t_stack *stack_b);

//utils.c
void	swap(t_stack **stack);
void	push(t_stack **stack, t_stack **node);
void 	rev_rotate(t_stack **stack);
void	rotate(t_stack **stack);
void	ft_lstadd_front_ps(t_stack **lst, t_stack *new);

//operations_1.c
void sa(t_stack **stack_a);
void sb(t_stack **stack_b);
void ss(t_stack **stack_a, t_stack **stack_b);
void pa(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_a, t_stack **stack_b);


//operations_2.c
void ra(t_stack **stack_a);
void rb(t_stack **stack_b);
void rr(t_stack **stack_a, t_stack **stack_b);

//operations_3.c
void rra(t_stack **stack_a);
void rrb(t_stack **stack_b);
void rrr(t_stack **stack_a, t_stack **stack_b);

//sort_arg_1.c
void	sort_three_a(t_stack **stack_a);
void	sort_three_b(t_stack **stack_b);
t_stack *get_high_val(t_stack *stack);
t_stack *get_low_val(t_stack *stack);

//freeErr.c
void ft_free(t_stack **stack);
void freetemp(char **temp);
void errorescape(t_stack *stack);
int errors(char *num);
int error_dup(t_stack *stack, int i);

//ft_split_ps.c
char	**ft_split_ps(const char *s, char c);

//calc.c
t_stack *closest_neighbor_node(t_stack *stack_b, t_stack *element);
t_stack  *closest_val(t_stack *stack_a, t_stack *stack_b);
void pop_cost_b(t_stack *stack_b);
void lowest_operator(t_stack *stack);
t_stack *find_lowest(t_stack *stack);

//big_sort.c
void push_swap(t_stack **stack_a, t_stack **stack_b);
void sort_b_stack(t_stack **stack_a, t_stack **stack_b);
int find_pos(t_stack *stack, int num);
void pop_cost_a(t_stack *stack_a);

//actions.c
t_stack *cheapest_operation(t_stack *a_stack, t_stack *b_stack, t_stack *low);
void rr_sort(t_stack *a_stack, t_stack *b_stack);
void rrr_sort(t_stack *a_stack, t_stack *b_stack);
void rrarb_sort(t_stack *a_stack, t_stack *b_stack);
void rarrb_sort(t_stack *a_stack, t_stack *b_stack);

#endif

