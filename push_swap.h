/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:22:11 by akwadran          #+#    #+#             */
/*   Updated: 2025/02/04 21:42:34 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h> //quitar
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				num;
	int				index;
	int				cost;
	bool			is_upper_half;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}			t_stack;

char	**format_arguments(int argc, char **argv);
void	free_array(char **args_array);
t_stack	*init_stack(char **args_array, int argc);
t_stack	*create_node(const char *arg);
void	print_stack(t_stack *stack); //quitar

bool	valid_arguments(char **args_array);

void	append_node_back(t_stack **stack, t_stack *new_node);
t_stack	*find_last(t_stack *stack);
void	free_stack(t_stack *stack);
void	append_node_front(t_stack **stack, t_stack *new_node);
int		stack_len(t_stack *stack);

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

void	sort(t_stack **a, t_stack **b);
void    push_to_b(t_stack **a, t_stack **b);
void	sort_three(t_stack **stack);
void    push_to_a(t_stack **a, t_stack **b);
void    rotate_a(t_stack **a);

void	reset_values(t_stack *stack);
void	set_targets_asc(t_stack *a, t_stack *b);
void	set_targets_desc(t_stack *a, t_stack *b);
void	calc_push_cost(t_stack *b, int len_a, int len_b);
void	rotate_for_push_to_b(t_stack **dst, t_stack **src, t_stack *cheapest);
void	rotate_for_push_to_a(t_stack **a, t_stack **b, t_stack *cheapest);
void	move_stacks(t_stack **a, t_stack **b, t_stack *cheapest, char dst_stack);

bool	is_sorted(t_stack *stack);
t_stack	*find_cheapest_node(t_stack *stack);
t_stack	*find_lowest_value(t_stack *stack);
t_stack	*find_highest_value(t_stack *stack);

#endif
