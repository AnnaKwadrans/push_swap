/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:22:11 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/25 20:29:00 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h> //quitar
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_stack
{
        int             num;
        int             push_price;
        int             index;
        bool            cheapest;
        struct s_stack  *next;
        struct s_stack  *prev;
        struct s_stack  *target;
}       t_stack;



char	**format_arguments(int argc, char** argv);
void	free_array(char **args_array);
t_stack	*init_stack(char **args_array, int argc);
t_stack *create_node(const char *arg);
void	print_stack(t_stack *stack); //quitar

void    append_node_back(t_stack **stack, t_stack *new_node);
t_stack *find_last(t_stack *stack);
void    free_stack(t_stack *stack);
void    append_node_front(t_stack **stack, t_stack *new_node);
bool	is_sorted(t_stack *stack);

//void	print_array(char **args_array); //quitar
//t_list	*init_list(char **args_array);
//void	print_list(t_list *stack); //quitar

t_stack	*swap(t_stack *stack);
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);

void	push(t_stack **stack1, t_stack **stack2);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

t_stack	*rotate(t_stack *stack);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);

t_stack	*reverse_rotate(t_stack *stack);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);

void	sort(t_stack **stack_a, t_stack **stack_b);

#endif
