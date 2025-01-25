/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:16:39 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/26 00:20:32 by akwadran         ###   ########.fr       */
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
        t_stack *cheapest;
        
        while (stack_len(*a) > 3)
                pb(a, b);
        sort_three(a);
        while (*b)
        {
                reset_values(*a);
                reset_values(*b);
                set_targets(*a, *b);
                calc_push_cost(*b);
                cheapest = find_cheapest_node(*b);
                move_stacks(a, b, cheapest);
                pa(a, b);
        }
}

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
                stack->cheapest = 0;
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
                        b->target = aux;
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

t_stack *find_cheapest_node(t_stack *b)
{
        t_stack *cheapest_node;

        cheapest_node = b;
        while (b && b->next)
        {
                if (b->cost > b->next->cost)
                        cheapest_node = b->next;
                b = b->next;
        }
        cheapest_node->cheapest = 1; // se puede quitar?
        return (cheapest_node);
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
