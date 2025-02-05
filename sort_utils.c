/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:16:39 by akwadran          #+#    #+#             */
/*   Updated: 2025/02/05 00:50:22 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_values(t_stack *stack)
{
	int	i;
	int	len;

	if (stack == NULL)
		return ;
	len = stack_len(stack);
	i = 0;
	while (stack)
	{
		stack->index = i;
		stack->cost = -1;
		/*
		if (stack->index + 1 <= len / 2)
			stack->is_upper_half = 1;
		else
			stack->is_upper_half = 0;
		*/
		
		if (len % 2 == 0 && stack->index + 1 <= len / 2)
			stack->is_upper_half = 1;
		else if (len % 2 == 1 && stack->index <= len / 2)
			stack->is_upper_half = 1;
		else
			stack->is_upper_half = 0;
		
		stack->target = NULL;
		i++;
		stack = stack->next;
	}
}

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

t_stack	*find_lowest_value(t_stack *stack)
{
	t_stack	*lowest;

	if (stack == NULL)
		return (NULL);
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

t_stack	*find_highest_value(t_stack *stack)
{
	t_stack	*highest;

	if (stack == NULL)
		return (NULL);
	//printf("check lv start\n");
	highest = stack;
	while (stack && stack->next)
	{
		if (stack->next->num > highest->num)
			highest = stack->next;
		stack = stack->next;
	}
	//printf("%p, %d\n", &lowest, lowest->num);
	return (highest);
}

t_stack	*find_cheapest_node(t_stack *stack)
{
	t_stack	*cheapest_node;

	if (stack == NULL)
		return (NULL);
	cheapest_node = stack;
	while (stack && stack->next)
	{
		if (cheapest_node->cost > stack->next->cost)
			cheapest_node = stack->next;
		//printf("cost cmp %d i %d: %d, num %d\n", stack->num, stack->next->num, stack->cost, stack->next->cost);
		//printf("cheapest node %d, num %d\n", cheapest_node->index, cheapest_node->num);
		stack = stack->next;
	}
	return (cheapest_node);
}
