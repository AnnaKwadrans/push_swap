/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 07:53:40 by akwadran          #+#    #+#             */
/*   Updated: 2025/02/05 01:29:56 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	set_targets_desc(t_stack *dst, t_stack *src)
{
	t_stack	*start_dst;
	t_stack	*highest_dst;

	if (dst == NULL || src == NULL)
		return ;
	start_dst = dst;
	while (src)
	{
		src->target = NULL;
		dst = start_dst;
		while (dst)
		{
			if ((dst->num < src->num && !src->target) || (dst->num < src->num
					&& dst->num > src->target->num))
				src->target = dst;
			dst = dst->next;
		}
		if (!src->target)
		{
			dst = start_dst;
			highest_dst = find_highest_value(dst);
			src->target = highest_dst;
		}
		src = src->next;
	}
}

void	set_targets_asc(t_stack *dst, t_stack *src)
{
	t_stack	*start_dst;
	t_stack	*lowest_dst;

	if (dst == NULL || src == NULL)
		return ;
	start_dst = dst;
	while (src)
	{
		src->target = NULL;
		dst = start_dst;
		while (dst)
		{
			if ((dst->num > src->num && !src->target) || (dst->num > src->num
					&& dst->num < src->target->num))
				src->target = dst;
			dst = dst->next;
		}
		if (!src->target)
		{
			dst = start_dst;
			lowest_dst = find_lowest_value(dst);
			src->target = lowest_dst;
		}
		src = src->next;
	}
}

void	calc_push_cost(t_stack *b, int len_a, int len_b)
{
	if (b == NULL)
		return ;
	while (b && b->target)
	{
		if (b->is_upper_half && b->target->is_upper_half)
			b->cost = b->index + b->target->index;
		else if (!b->is_upper_half && !b->target->is_upper_half)
			b->cost = len_b - b->index + len_a - b->target->index;
		else if (b->is_upper_half && !b->target->is_upper_half)
			b->cost = b->index + len_a - b->target->index;
		else if (!b->is_upper_half && b->target->is_upper_half)
			b->cost = len_b - b->index + b->target->index;
		b = b->next;
	}
}

void	rotate_for_push_to_b(t_stack **a, t_stack **b, t_stack *cheapest)
{
	if (cheapest->is_upper_half && cheapest->target->is_upper_half)
	{
		while (*b != cheapest->target && *a != cheapest)
			rr(a, b);
	}
	else if (!cheapest->is_upper_half && !cheapest->target->is_upper_half)
	{
		while (*b != cheapest->target && *a != cheapest)
			rrr(a, b);
	}
	while (*a != cheapest)
	{
		if (cheapest->is_upper_half)
			ra(a);
		else
			rra(a);
	}
	while (*b != cheapest->target)
	{
		if (cheapest->target->is_upper_half)
			rb(b);
		else
			rrb(b);
	}
}

void	rotate_for_push_to_a(t_stack **a, t_stack **b, t_stack *cheapest)
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
