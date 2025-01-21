/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:01:01 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/20 19:30:03 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_list	*ft_lst2last(t_list *lst)
{
	t_list	*aux;

	if (lst == NULL)
		return (NULL);
	aux = lst;
	while (aux->next->next != NULL)
		aux = aux->next;
	return (aux);
}

t_list	*reverse_rotate(t_list *stack)
{
	t_list	*last;
	t_list	*second_last;

	if (stack != NULL && stack->next != NULL)
	{
		last = ft_lstlast(stack);
		second_last = ft_lst2last(stack);
		second_last->next = NULL;
		ft_lstadd_front(&stack, last);
	}
	return (stack);
}

void	rra(t_list **stack)
{
	*stack = reverse_rotate(*stack);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_list **stack)
{
	*stack = reverse_rotate(*stack);
	ft_putendl_fd("rrb", 1);
}
void	rrr(t_list **stack_a, t_list **stack_b)
{
	*stack_a = reverse_rotate(*stack_a);
	*stack_b = reverse_rotate(*stack_b);
	ft_putendl_fd("rrr", 1);
}
