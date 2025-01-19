/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:30:42 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/19 14:17:05 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	while(stack != NULL && stack->next != NULL)
	{
		if (ft_atoi(stack->next->content) < ft_atoi(stack->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort(t_list *stack_a, t_list *stack_b)
{
	if (is_sorted(stack_a))
		exit(0);
	if (ft_atoi(stack_a->content) < ft_atoi(stack_a->next->content))
	{
		pb(&stack_a, &stack_b);
	}
	if (ft_atoi(stack_a->content) > ft_atoi(stack_a->next->content))
	{
		sa(&stack_a);
	}
}
