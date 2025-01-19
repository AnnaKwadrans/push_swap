/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:16:32 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/19 13:27:09 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*swap(t_list *stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (stack->next != NULL && stack != NULL)
	{
		first = stack;
		second = stack->next;
		third = stack->next->next;
		stack = second;
		stack->next = first;
		stack->next->next = third;
	}
	return (stack);
}

void	sa(t_list **stack)
{
	if ((*stack)->next != NULL && *stack != NULL)
	{
		*stack = swap(*stack);
		ft_putendl_fd("sa", 1);
	}
}

void	sb(t_list **stack)
{
	if ((*stack)->next != NULL && *stack != NULL)
	{
		*stack = swap(*stack);
		ft_putendl_fd("sb", 1);
	}
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->next != NULL && *stack_a != NULL && (*stack_b)->next != NULL && *stack_b != NULL)
	{
		*stack_a = swap(*stack_a);
		*stack_b = swap(*stack_b);
		ft_putendl_fd("ss", 1);
	}
}
