/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:21:01 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/06 17:30:49 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**args_array;
	t_list	*stack_a;

	args_array = format_arguments(argc, argv);
	//print_array(args_array); //quitar
	stack_a = NULL;
	stack_a = init_list(args_array);
	print_list(stack_a);
	ft_lstclear(stack_a, free);
	return (0);
}
