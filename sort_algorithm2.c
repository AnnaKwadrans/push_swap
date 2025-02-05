/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 07:53:40 by akwadran          #+#    #+#             */
/*   Updated: 2025/02/05 01:16:55 by akwadran         ###   ########.fr       */
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
			//printf("!b->target\n");
			dst = start_dst;
			highest_dst = find_highest_value(dst);
			//printf("%d\n", lowest_a->num);
			//printf("%p\n", &lowest_a);
			src->target = highest_dst;
			//printf("%p, %d\n", b->target, b->target->num);
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
			//printf("!b->target\n");
			dst = start_dst;
			lowest_dst = find_lowest_value(dst);
			//printf("%d\n", lowest_a->num);
			//printf("%p\n", &lowest_a);
			src->target = lowest_dst;
			//printf("%p, %d\n", b->target, b->target->num);
		}
		src = src->next;
	}
}

void	calc_push_cost(t_stack *b, int len_a, int len_b)
{
	// CORREGIR
	
	/*printf("calc_push_cost\nSTACK B\n");  // QUITAR
	print_stack(b);      // QUITAR */
	if (b == NULL)
		return ;
	/*
	while (b && b->target)
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
				b->cost = len_b - b->index;
			else
				b->cost = len_a - b->target->index;
		}
		else if (b->is_upper_half && !b->target->is_upper_half)
			b->cost = b->index + len_a - b->target->index;
		else if (!b->is_upper_half && b->target->is_upper_half)
			b->cost = len_b - b->index + b->target->index;
		b = b->next;
	}
	*/


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

/*
	while (b && b->target)
	{
		if (b->is_upper_half)
			b->cost = b->index;
		else 
			b->cost = len_b - b->index;
		if (b->target->is_upper_half)
			b->cost += b->target->index;
		else
			b->cost += len_a - b->target->index;
		b = b->next;
	}
*/
}

static void	rotate_2stacks(t_stack **a, t_stack **b, t_stack *cheapest)
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

void	move_stacks(t_stack **dst, t_stack **src, t_stack *cheapest, char dst_stack)
{
	//printf("m_s_cheapest idx %d, num %d\n", cheapest->index, cheapest->num);
	if (!cheapest || !(*dst) || !(*src))
		return ;
	if (cheapest->index == 1 && cheapest->target->index == 1)
		ss(src, dst);
	else if ((cheapest->index == 1 && dst_stack == 'a')
			|| (cheapest->target->index == 1 && dst_stack == 'b'))
		sb(src);
	else if ((cheapest->target->index == 1 && dst_stack == 'a')
			|| (cheapest->index == 1 && dst_stack == 'b'))
		sa(dst);
	//else
	//{
		rotate_2stacks(dst, src, cheapest);
		if (dst_stack == 'a')
		{
			while (*src != cheapest)
			{
				if (cheapest->is_upper_half)
					rb(src);
				else
					rrb(src);
			}
			while (*dst != cheapest->target)
			{
				if (cheapest->target->is_upper_half)
					ra(dst);
				else
					rra(dst);
			}
		}
		else if (dst_stack == 'b')
		{
			while (*src != cheapest)
			{
				if (cheapest->is_upper_half)
					ra(src);
				else
					rra(src);
			}
			while (*dst != cheapest->target)
			{
				if (cheapest->target->is_upper_half)
					rb(dst);
				else
					rrb(dst);
			}
		}
	//}
}
