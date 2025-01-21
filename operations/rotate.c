/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:42:46 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/20 19:30:12 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*rotate(t_list *stack)
{
	t_list	*first;

	if (stack != NULL && stack->next != NULL)
	{
		first = stack;
		stack = stack->next;
		ft_lstadd_back(&stack, first);
		first->next = NULL;
	}
	return (stack);
}

void	ra(t_list **stack)
{
	if (*stack != NULL && (*stack)->next != NULL)
	{
		*stack = rotate(*stack);
		ft_putendl_fd("ra", 1);
	}
}

void	rb(t_list **stack)
{
	if (*stack != NULL && (*stack)->next != NULL)
	{
		*stack = rotate(*stack);
		ft_putendl_fd("rb", 1);
	}
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a != NULL && (*stack_a)->next != NULL && *stack_b != NULL && (*stack_b)->next != NULL)
	{
		*stack_a = rotate(*stack_a);
		*stack_b = rotate(*stack_b);
		ft_putendl_fd("rr", 1);
	}
}
