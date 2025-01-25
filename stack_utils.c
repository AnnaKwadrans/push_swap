/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:01:00 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/25 20:20:15 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    append_node_back(t_stack **stack, t_stack *new_node)
{
        t_stack *last_node;
        
        if (new_node)
        {
                if (*stack == NULL)
                        *stack = new_node;
                else
                {
                        last_node = find_last(*stack);
                        last_node->next = new_node;
                        new_node->prev = last_node;
                }
        }
}

t_stack *find_last(t_stack *stack)
{
        if (!stack)
                return (NULL);
        while (stack && stack->next)
        {
                stack = stack->next;
        }
        return (stack);
}

void    free_stack(t_stack *stack)
{
        t_stack *aux;
        
        while (stack)
        {
                aux = stack->next;
                free(stack);
                stack = aux;
        }
}

void    append_node_front(t_stack **stack, t_stack *new_node)
{
        if (new_node)
        {
                if (!*stack)
                        *stack = new_node;
                else
                {
                        (*stack)->prev = new_node;
                        new_node->next = *stack;
                        *stack = new_node;
                }
        }
}

bool	is_sorted(t_stack *stack)
{
	while(stack && stack->next)
	{
		if (stack->next->num < stack->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}
