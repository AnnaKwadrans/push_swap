/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:30:42 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/23 19:24:24 by akwadran         ###   ########.fr       */
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

static int	last_to_int(t_list *stack)
{
	t_list	*aux;

	aux = ft_lstlast(stack);
	return (ft_atoi(aux->content));
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int n = 0;
	
	while (ft_lstsize(*stack_a) > 1 /*&& n < 5*/)
	{
		//printf("loop %d\n", n);
		if (ft_atoi((*stack_a)->content) > ft_atoi((*stack_a)->next->content))
		{
			sa(&stack_a);
			//print_list(stack_a);
			//printf("*\n");
			//print_list(stack_b);
		}
		else if (ft_atoi((*stack_a)->content) < ft_atoi((*stack_a)->next->content) && 
			(*stack_b == NULL || ft_atoi((*stack_a)->content) > ft_atoi((*stack_b)->content)))
		{
			pb(&stack_a, &stack_b);
			//print_list(stack_a);
			//printf("*\n");
			//print_list(stack_b);
		}
		else if (ft_atoi((*stack_a)->content) < ft_atoi((*stack_a)->next->content) && 
			ft_atoi((*stack_a)->content) > ft_atoi((*stack_b)->content) && 
			(ft_atoi((*stack_a)->content) < last_to_int(*stack_b) || ft_lstsize(*stack_b) == 1))
		{
			pb(&stack_a, &stack_b);
			//print_list(stack_a);
			//printf("*\n");
			//print_list(stack_b);
		}
		//else if (ft_atoi(stack_a->content) < ft_atoi((ft_lstlast(stack_b->content))))
		else if (ft_atoi((*stack_a)->content) < ft_atoi((*stack_a)->next->content) && 
			ft_atoi((*stack_a)->content) < ft_atoi((*stack_b)->content) &&
			(ft_atoi((*stack_a)->content) < last_to_int(*stack_b) || ft_lstsize(*stack_b) == 1))
		{
			pb(&stack_a, &stack_b);
			rb(&stack_b);
			//print_list(stack_a);
			//printf("*\n");
			//print_list(stack_b);
		}
		else if (ft_atoi((*stack_a)->content) < ft_atoi((*stack_a)->next->content) && 
			ft_atoi((*stack_a)->content) < ft_atoi((*stack_b)->content) &&
			ft_atoi((*stack_a)->content) > last_to_int(*stack_b))
		{
			while (ft_atoi((*stack_a)->content) < ft_atoi((*stack_b)->content))
			{
				rb(&stack_b);
				//print_list(stack_a);
				//printf("*\n");
				//print_list(stack_b);
			}
			pb(&stack_a, &stack_b);
			//print_list(stack_a);
			//printf("*\n");
			//print_list(stack_b);
		}
		n++;
	}
	if (ft_atoi((*stack_a)->content) > ft_atoi((*stack_b)->content) && 
		ft_atoi((*stack_a)->content) < last_to_int(*stack_b))
	{
		pb(&stack_a, &stack_b);
		//print_list(stack_a);
		//printf("*\n");
		//print_list(stack_b);
	}
	else if (ft_atoi((*stack_a)->content) < ft_atoi((*stack_b)->content) && 
		ft_atoi((*stack_a)->content) < last_to_int(*stack_b))
	{
		pb(&stack_a, &stack_b);
		rb(&stack_b);
		//print_list(stack_a);
		//printf("*\n");
		//print_list(stack_b);
	}
	else if (ft_atoi((*stack_a)->content) < ft_atoi((*stack_b)->content) && 
		ft_atoi((*stack_a)->content) > last_to_int(*stack_b))
	{
		while (ft_atoi((*stack_a)->content) < ft_atoi((*stack_b)->content))
		{
			rb(&stack_b);
			//print_list(stack_a);
			//printf("*\n");
			//print_list(stack_b);
		}
		pb(&stack_a, &stack_b);
		//print_list(stack_a);
		//printf("*\n");
		//print_list(stack_b);
	}
	//if (is_sorted(stack_a) && ft_atoi(stack_a->content) > ft_atoi(stack_b->content))
	//{
		while (*stack_b != NULL)
		{
			pa(&stack_a, &stack_b);
			//print_list(stack_a);
			//printf("*\n");
			//print_list(stack_b);
		}
	//}
	//else
	//{
	//	sort(stack_a, stack_b);
	//}
}
