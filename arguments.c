/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:22:02 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/04 14:53:00 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


t_list	*format_parameters(int argc, char** argv)
{
	char	**parameters;
	t_list	*stack_a;
	int	args_cont;
	int	i;

	stack_a = NULL;
	args_cont = 1;
	while (args_cont <= argc)
	{
		parameters = ft_split(argv[args_cont], ' ');
		i = 0;
		if (stack_a == NULL)
		{
			stack_a->content = ft_lstnew(ft_atoi(parameters[i]));
			i++;
		}
		while (parameters[i] != NULL)
		{
			ft_lstadd_back(&stack_a, ft_atoi(parameters[i]));
			i++;
		}
		free(parameters);
		args_cont++;
	}
	return (stack_a);
}
