/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:21:01 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/19 13:14:14 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**args_array;
	t_list	*stack_a;
	t_list	*stack_b;
	char	**array_test;	// quitar

	args_array = format_arguments(argc, argv);
	//print_array(args_array); //quitar
	stack_a = NULL;
	stack_a = init_list(args_array);
	print_list(stack_a); //quitar
	//stack_a = swap(stack_a);
	//print_list(stack_a); //quitar
	//sa(&stack_a);
	//print_list(stack_a);
	//sb(&stack_a);
	//print_list(stack_a);
	//ft_putstr_fd("*************", 1);
	printf("%d\n", is_sorted(stack_a));
	array_test = ft_split("11 12 13 14 15", ' ');
	stack_b = init_list(array_test);
	print_list(stack_b);
	printf("%d\n", is_sorted(stack_b));
	//ss(&stack_a, &stack_b);
	//push(stack_a, stack_b);
	//stack_b = reverse_rotate(stack_b);
	//print_list(stack_a);
	//print_list(stack_b);
	//rrr(&stack_a, &stack_b);
	/*
	pa(&stack_a, &stack_b);
	print_list(stack_a);
	print_list(stack_b);
	pb(&stack_a, &stack_b);
	print_list(stack_a);
	print_list(stack_b);
	*/
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
