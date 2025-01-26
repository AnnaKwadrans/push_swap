/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 07:53:40 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/26 08:01:20 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    reset_values(t_stack *stack)
{
        int     i;
        int     len;
        
        len = stack_len(stack);
        i = 0;
        while (stack)
        {
                stack->index = i;
                if (stack->index < len / 2)
                        stack->is_upper_half = 1;
                else
                        stack->is_upper_half = 0;
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
                        b->target = find_lowest_value(a);
               b = b->next;
        }
}

void    calc_push_cost(t_stack *b)
{
        while (b)
        {
                if (b->is_upper_half && b->target->is_upper_half)
                {
                        if (b->index > b->target->index)
                                b->cost = b->index;
                        else
                                b->cost = b->target->index;
                }
                else if (!b->is_upper_half && !b->target->is_upper_half)
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

void    move_stacks(t_stack **a, t_stack **b, t_stack *cheapest)
{
        if (cheapest->is_upper_half && cheapest->target->is_upper_half)
        {
                while (*a != cheapest->target && *b != cheapest)
                        rr(a, b);
        }
        else if (!cheapest->is_upper_half && !cheapest->target->is_upper_half)
        {
                while (*a != cheapest->target && *b != cheapest)
                        rrr(a, b);
        }
        while (*b != cheapest)
        {
                if (cheapest->is_upper_half)
                        rb(b);
                else
                        rrb(b);
        }
        while (*a != cheapest->target)
        {
                if (cheapest->target->is_upper_half)
                        ra(a);
                else
                        rra(a);
        }
}
