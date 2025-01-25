/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:55:29 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/25 20:19:55 by akwadran         ###   ########.fr       */
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
	else if (argc > 2)
		args_array = argv + 1;
	return (args_array);
}

void	free_array(char **args_array)
{
	int	i;

	i = 0;
	while (args_array[i] != NULL)
		free(args_array[i++]);
	free(args_array);
}

t_stack	*init_stack(char **args_array, int argc)
{
	t_stack	*stack_a;
	int	i;

	i = 0;
	stack_a = create_node(args_array[i]);
	i++;
	while (args_array[i] != NULL)
	{
		append_node_back(&stack_a, create_node(args_array[i]));
		i++;
	}
	if (argc == 2)
        {
                free(args_array);
	        args_array = NULL;
        }
        return (stack_a);
}

t_stack *create_node(const char *arg)
{
        t_stack *new_node;

        new_node = (t_stack *)malloc(sizeof(t_stack));
        if (!new_node)
                return (NULL);
        new_node->num = ft_atoi(arg);
        new_node->next = NULL;
        new_node->prev = NULL;
        new_node->target = NULL;
        return (new_node);
}

void	print_stack(t_stack *stack) //quitar
{
	while (stack != NULL)
	{
		printf("%d\n", stack->num);
		stack = stack->next;
	}
}
