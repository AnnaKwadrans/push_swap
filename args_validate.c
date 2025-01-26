/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:57:52 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/26 14:18:40 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_number(char c)
{
	if (!(ft_isdigit(c) || c == '-'))
		return (0);
	return (1);
}

static bool	int_overflow(char *str)
{
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		return (1);
	return (0);
}

static bool	is_duplicated(char **args_array)
{
	int	i;
	int	j;

	i = 0;
	while (args_array[i])
	{
		j = 1;
		while (args_array[i + j])
		{
			if (ft_strncmp(args_array[i], args_array[i + j], 11) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

bool	valid_arguments(char **args_array)
{
	int	i;
	int	j;

	i = 0;
	while (args_array[i])
	{
		j = 0;
		while (args_array[i][j])
		{
			if (!is_number(args_array[i][j]))
				return (0);
			j++;
		}
		if (int_overflow(args_array[i]))
			return (0);
		i++;
	}
	if (is_duplicated(args_array))
		return (0);
	return (1);
}
