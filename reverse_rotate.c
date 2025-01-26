/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:01:01 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/26 14:15:50 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_2last(t_stack *lst)
{
	t_stack	*aux;

	if (!lst)
		return (NULL);
	aux = lst;
	while (aux->next->next)
		aux = aux->next;
	return (aux);
}

t_stack	*reverse_rotate(t_stack *stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (stack && stack->next)
	{
		last = find_last(stack);
		second_last = find_2last(stack);
		second_last->next = NULL;
		append_node_front(&stack, last);
	}
	return (stack);
}

void	rra(t_stack **stack)
{
	*stack = reverse_rotate(*stack);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **stack)
{
	*stack = reverse_rotate(*stack);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = reverse_rotate(*stack_a);
	*stack_b = reverse_rotate(*stack_b);
	ft_putendl_fd("rrr", 1);
}
