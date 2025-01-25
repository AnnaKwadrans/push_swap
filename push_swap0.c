/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:33:40 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/04 17:58:00 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // quitar
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	//t_list	*stack_b;
	
	//arguments
	// Algunos de los posibles errores son: argumentos que no son enteros, argumentos superiores a un número entero, y/o encontrar números duplicados.
	if (argc <= 1)
		return (0);
	stack_a = format_arguments(argc, argv);

	while (stack_a != NULL)
	{
		printf("%d\n", *((int *)stack_a->content));
	}
	
	//ft_lstmap(stack_a, printf("%d\n", *((int *)stack_a->content)), free);
	ft_lstclear(&stack_a, free);
	
	return (0);
}
