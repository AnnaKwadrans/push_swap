/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:36:25 by akwadran          #+#    #+#             */
/*   Updated: 2025/02/05 01:22:04 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args_array;
	
	a = NULL;
	b = NULL;
	args_array = format_arguments(argc, argv);
	a = init_stack(args_array, argc);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort(&a, &b);
	}
	free_stack(a);
	free_stack(b);
	return (0);
}
