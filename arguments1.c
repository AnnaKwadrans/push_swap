/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:24:30 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/08 19:20:32 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**format_arguments(int argc, char **argv)
{
	char	**args_array;
	
	args_array = NULL;
	if (argc <= 1)
		exit(1);
	else if (argc == 2)
		args_array = ft_split(argv[1], ' ');
	// else if (argc > 2)
	return (args_array);
}

void	print_array(char **args_array) //quitar
{
	int	i;

	i = 0;
	while (args_array[i] != NULL)
	{
		printf("%s\n", args_array[i]);
		free(args_array[i]);
		i++;
	}
	free(args_array);
}

t_list	*init_list(char **args_array)
{
	t_list	*stack_a;
	int	i;

	i = 0;
	stack_a = ft_lstnew(args_array[i]);
	i++;
	while (args_array[i] != NULL)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(args_array[i]));
		i++;
	}
	return (stack_a);
}

void	print_list(t_list *stack) //quitar
{
	char	*temp;
	
	while (stack != NULL)
	{
		temp = ft_strdup(stack->content);
		printf("%s\n", temp);
		free(temp);
		stack = stack->next;
	}
}
