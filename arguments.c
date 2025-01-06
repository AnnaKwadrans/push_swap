/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:22:02 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/06 12:18:36 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
/*
static t_list	*split_parameter(char *str)
{
	int	i;
	int	len;
	int	new;
	
	i = 0;
	len = 0;
	new = 0;
	t_list	*a = NULL;
	while (str[i])
	{
		if (ft_isspace(str[i]) && !new)
			i++;
		if (ft_isdigit(str[i]))
		{
			new = 1;
			len++;
		}
		if (ft_isspace(str[i]) && new)
		{
			//convert str to int
		}
		if (!ft_isdigit(str[i]) || !ft_isspace(str[i]))
		{
			ft_putstr_fd("Error\n", 1);
			return (NULL);
		}
		
	}
	return (a);
}

t_list	format_parameters(int argc, char** argv)
{
	t_list	a;
	int	n;
	char	**param;

	n = 1;
	while (n <= argc)
	{
		a.content = split_parameter(argv[n]);
		n++;
	}
	return (a);
}
*/
char	**get_char_array(int argc, char **argv)
{
	char	**args_char;
	int	num_args;
	int	i;

	printf("ARG[1]: %s\n", argv[1]);
	args_char = ft_split(argv[1], ' ');
	num_args = 2;
	while (num_args <= argc)
	{
		i = 0;
		while (args_char[i] != NULL)
			i++;
		args_char[i] = *ft_split(argv[num_args], ' ');
		num_args++;
	}
	return (args_char);
}

//int	**get_int_array(char **args_char)
//{
//	return (0);
//}

t_list	*format_arguments(int argc, char **argv)
{
	char	**args_char;
	//int	**args_int;
	
	//get char array
	args_char = get_char_array(argc, argv);
	printf("args char\n");
	int i = 0;
	while (args_char[i] != NULL)
	{
		printf("%s\n", args_char[i]);
		free(args_char[i]);
		i++;
	}
	free(args_char);
	//get int array
	//args_int = get_int_array(args_char);
	//create list
	
	
	
	t_list	*list = NULL;
	return (list);
	
	
	
	
	/*
	char	**args_char;
	char	**args_char_aux;
	int	**args_int;
	t_list	*stack_a;
	int	args_cont;
	int	i;

	//stack_a = NULL;
	args_char = ft_split(argv[1], ' ');
	args_cont = 2;
	while (args_cont <= argc)
	{
		
		
		args_char = ft_split(argv[args_cont], ' ');
		*/
		/*i = 0;
		if (stack_a == NULL)
		{
			stack_a->content = ft_lstnew(ft_atoi(parameters[i]));
			i++;
		}*/
		/*
		while (parameters[i] != NULL)
		{
			ft_lstadd_back(&stack_a, ft_atoi(parameters[i]));
			i++;
		}
		free(parameters);
		args_cont++;
	}
	return (stack_a);
	*/
}
