/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:22:11 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/19 14:08:18 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h> //quitar
# include "Libft/libft.h"

char	**format_arguments(int argc, char** argv);
void	print_array(char **args_array); //quitar
t_list	*init_list(char **args_array);
void	print_list(t_list *stack); //quitar

t_list	*swap(t_list *stack);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);

void	push(t_list **stack1, t_list **stack2); // no funciona
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

t_list	*rotate(t_list *stack);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);

t_list	*reverse_rotate(t_list *stack);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);

int	is_sorted(t_list *stack);

#endif
