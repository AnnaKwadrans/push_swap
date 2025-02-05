/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:05:26 by akwadran          #+#    #+#             */
/*   Updated: 2025/02/05 00:47:53 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
        push_to_b(a, b);
	sort_three(a);
        push_to_a(a, b);
        rotate_a(a);
}

void    push_to_b(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3)
	{
		// REVISAR
		
		if (stack_len(*b) > 1)
		{
			reset_values(*a);
			reset_values(*b);
			set_targets_desc(*b, *a);
			/*
			printf("STACK A\n");  // QUITAR
			print_stack(*a);      // QUITAR
			printf("STACK B\n");  // QUITAR
			print_stack(*b);      // QUITAR
			*/
			calc_push_cost(*a, stack_len(*b), stack_len(*a));
			/*
			printf("STACK A\n");  // QUITAR
			print_stack(*a);      // QUITAR
			printf("STACK B\n");  // QUITAR
			print_stack(*b);      // QUITAR
			t_stack *cheap = find_cheapest_node(*a);
			printf("cheapest idx %d, num %d\n", cheap->index, cheap->num);
			*/
			rotate_for_push_to_b(a, b, find_cheapest_node(*a));
		}
		pb(a, b);
	}
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

void    push_to_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		reset_values(*a);
		reset_values(*b);
		set_targets_asc(*a, *b);
		calc_push_cost(*b, stack_len(*a), stack_len(*b));
		/*
		printf("STACK A\n");  // QUITAR
		print_stack(*a);      // QUITAR
		printf("STACK B\n");  // QUITAR
		print_stack(*b);      // QUITAR
		t_stack *cheap = find_cheapest_node(*b);
		printf("cheapest idx %d, num %d\n", cheap->index, cheap->num);
		*/
		rotate_for_push_to_a(a, b, find_cheapest_node(*b));
		pa(a, b);
		/*
		printf("STACK A\n");  // QUITAR
		print_stack(*a);      // QUITAR
		printf("STACK B\n");  // QUITAR
		print_stack(*b);      // QUITAR
		*/
	}
	/*
	printf("STACK A\n");  // QUITAR
	print_stack(*a);      // QUITAR
	*/
}

void    rotate_a(t_stack **a)
{
	reset_values(*a);
	while (*a != find_lowest_value(*a))
	{
		if (find_lowest_value(*a)->is_upper_half)
			ra(a);
		else
			rra(a);
	}
	/*
	printf("STACK A\n");  // QUITAR
	print_stack(*a);      // QUITAR
	*/
}
