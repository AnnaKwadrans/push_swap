/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:42:46 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/25 20:06:02 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*rotate(t_stack *stack)
{
	t_stack	*first;

	if (stack && stack->next)
	{
		first = stack;
		stack = stack->next;
		stack->prev = NULL;
		append_node_back(&stack, first);
		first->next = NULL;
	}
	return (stack);
}

void	ra(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		*stack = rotate(*stack);
		ft_putendl_fd("ra", 1);
	}
}

void	rb(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		*stack = rotate(*stack);
		ft_putendl_fd("rb", 1);
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
	{
		*stack_a = rotate(*stack_a);
		*stack_b = rotate(*stack_b);
		ft_putendl_fd("rr", 1);
	}
}
