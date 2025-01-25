/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:16:32 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/25 20:15:15 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap(t_stack *stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (stack->next && stack)
	{
		first = stack;
		second = stack->next;
		third = stack->next->next;
		stack = second;
		stack->prev = NULL;
		stack->next = first;
		stack->next->prev = second;
		stack->next->next = third;
	}
	return (stack);
}

void	sa(t_stack **stack)
{
	if ((*stack)->next && *stack)
	{
		*stack = swap(*stack);
		ft_putendl_fd("sa", 1);
	}
}

void	sb(t_stack **stack)
{
	if ((*stack)->next && *stack)
	{
		*stack = swap(*stack);
		ft_putendl_fd("sb", 1);
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->next && *stack_a && (*stack_b)->next && *stack_b)
	{
		*stack_a = swap(*stack_a);
		*stack_b = swap(*stack_b);
		ft_putendl_fd("ss", 1);
	}
}
