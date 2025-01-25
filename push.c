/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:07:45 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/25 19:30:18 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*stack2_second;
	t_stack	*stack2_first;

	if (*stack2)
	{
		stack2_first = *stack2;
		stack2_second = (*stack2)->next;
		append_node_front(stack1, stack2_first);
		*stack2 = stack2_second;
		(*stack2)->prev = NULL;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b)
	{
		push(stack_a, stack_b);
		ft_putendl_fd("pa", 1);
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a)
	{
		push(stack_b, stack_a);
		ft_putendl_fd("pb", 1);
	}
}
