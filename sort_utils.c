/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 07:53:40 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/26 15:52:11 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_values(t_stack *stack)
{
	int	i;
	int	len;

	len = stack_len(stack);
	i = 0;
	while (stack)
	{
		stack->index = i;
		stack->cost = -1;
		if (stack->index <= len / 2)
			stack->is_upper_half = 1;
		else
			stack->is_upper_half = 0;
		stack->target = NULL;
		i++;
		stack = stack->next;
	}
}

void	set_targets(t_stack *a, t_stack *b)
{
	t_stack	*start_a;
	t_stack	*lowest_a;

	start_a = a;
	while (b)
	{
		b->target = NULL;
		a = start_a;
		while (a)
		{
			if ((a->num > b->num && !b->target) || (a->num > b->num
					&& a->num < b->target->num))
				b->target = a;
			a = a->next;
		}
		if (!b->target)
		{
			//printf("!b->target\n");
			a = start_a;
			lowest_a = find_lowest_value(a);
			//printf("%d\n", lowest_a->num);
			//printf("%p\n", &lowest_a);
			b->target = lowest_a;
			//printf("%p, %d\n", b->target, b->target->num);
		}
		b = b->next;
	}
}

void	calc_push_cost(t_stack *b)
{
	// CORREGIR
	
	/*printf("calc_push_cost\nSTACK B\n");  // QUITAR
	print_stack(b);      // QUITAR */
	int	cost_b;
	int	cost_target;
	int	len_b;
	int	len_a;

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
			b->cost = b->index + b->target->index; // ESTÁ MAL
		b = b->next;
	}
}

void	move_stacks(t_stack **a, t_stack **b, t_stack *cheapest)
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
