/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:16:39 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/26 15:31:54 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->next->num < stack->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_three(t_stack **stack)
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
	{
		// REVISAR
		pb(a, b);
	}
	sort_three(a);
	while (*b)
	{
		reset_values(*a);
		reset_values(*b);
		set_targets(*a, *b);
		calc_push_cost(*b);
		printf("STACK A\n");  // QUITAR
		print_stack(*a);      // QUITAR
		printf("STACK B\n");  // QUITAR
		print_stack(*b);      // QUITAR
		move_stacks(a, b, find_cheapest_node(*b));
		pa(a, b);
		/*
		printf("STACK A\n");  // QUITAR
		print_stack(*a);      // QUITAR
		printf("STACK B\n");  // QUITAR
		print_stack(*b);      // QUITAR
		*/
	}
	reset_values(*a);
	while (*a != find_lowest_value(*a))
	{
		if (find_lowest_value(*a)->is_upper_half)
			ra(a);
		else
			rra(a);
	}
}

t_stack	*find_lowest_value(t_stack *stack)
{
	t_stack	*lowest;

	//printf("check lv start\n");
	lowest = stack;
	while (stack && stack->next)
	{
		if (stack->next->num < lowest->num)
			lowest = stack->next;
		stack = stack->next;
	}
	//printf("%p, %d\n", &lowest, lowest->num);
	return (lowest);
}

t_stack	*find_cheapest_node(t_stack *b)
{
	t_stack	*cheapest_node;

	cheapest_node = b;
	while (b && b->next)
	{
		if (b->cost > b->next->cost)
			cheapest_node = b->next;
		b = b->next;
	}
	return (cheapest_node);
}
