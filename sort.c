/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:16:39 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/25 22:59:09 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void    sort_three(t_stack **stack)
{       
        if ((*stack)->num > (*stack)->next->num 
                        && (*stack)->num > (*stack)->next->next->num)
                ra(stack);
        else if ((*stack)->next->num > (*stack)->num 
                        && (*stack)->next->num > (*stack)->next->next->num)
                rra(stack);
        if ((*stack)->num > (*stack)->next->num)
                sa(stack);
}

void	sort(t_stack **a, t_stack **b)
{
        while (stack_len(*a) > 3)
                pb(a, b);
        sort_three(*a);
        while (*b)
        {
                set_index(*a);
                set_index(*b);
                set_targets(*a, *b);
                calc_push_cost(*a, *b);
                move_stacks(a, b);
        }
}

void    set_index(t_stack *stack)
{
        int     i;
        
        i = 0;
        while (stack)
        {
                stack->index = i;
                i++;
                stack = stack->next;
        }
}

void    set_targets(t_stack *a, t_stack *b)
{
        t_stack *aux;

        aux = a;
        while (b)
        {
               b->target = NULL;
               a = aux;
               while (a)
               {
                        if ((a->num > b->num && !b->target) || (a->num > b->num 
                                        && a->num < b->target->num))
                                b->target = a;
                        a = a->next;
               }
               if (!b->target)
                        b->target = a;
               b = b->next;
        }
}

static bool     is_upper(t_stack *stack, int len)
{
        if (stack->index < len)
                return (1);
        else
                return (0);
}

void    calc_push_cost(t_stack *a, t_stack *b)
{
        int     len_a;
        int     len_b;

        len_a = stack_len(a);
        len_b = stack_len(b);
        while (b)
        {
                if (is_upper(b, len_b) && is_upper(b->target, len_a))
                {
                        if (b->index > b->target->index)
                                b->cost = b->index;
                        else
                                b->cost = b->target->index;
                }
                else if (!is_upper(b, len_b) && !is_upper(b->target, len_a))
                {
                        if (b->index < b->target->index)
                                b->cost = b->index;
                        else
                                b->cost = b->target->index;
                }
                else
                        b->cost = b->index + b->target->index;
                b = b->next;
        }
}

void    move_stacks(t_stack **a, t_stack **b)
{
        
}