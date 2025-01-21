/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:07:45 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/20 19:29:52 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list **stack1, t_list **stack2)
{
	t_list	*stack2_second;
	t_list	*stack2_first;

	if (*stack2 != NULL)
	{
		stack2_first = *stack2;
		stack2_second = (*stack2)->next;
		ft_lstadd_front(stack1, stack2_first);
		*stack2 = stack2_second;
	}
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	if (*stack_b != NULL)
	{
		push(stack_a, stack_b);
		ft_putendl_fd("pa", 1);
	}
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a != NULL)
	{
		push(stack_b, stack_a);
		ft_putendl_fd("pb", 1);
	}
}
