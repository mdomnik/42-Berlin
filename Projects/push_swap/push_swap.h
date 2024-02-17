/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:20:15 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/17 17:10:34 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libraries/Libft/libft.h"
# include "libraries/ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

//doubly linked list
typedef struct s_stack {
	
	int   data;
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
void	sort_three(t_stack **stack_a);
t_stack *get_high_val(t_stack *stack);
void push_swap(t_stack **stack_a, t_stack **stack_b);

#endif

