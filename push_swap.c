/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:22:02 by akwadran          #+#    #+#             */
/*   Updated: 2024/12/29 20:52:24 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static struct s_stack	*split_parameter(char *str)
{
	int	i;
	 i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || !ft_isspace(str[i]))
		{
			ft_putstr_fd("Error\n", 1);
			return (NULL);
		}
	}
}

struct s_stack	format_parameters(int argc, char** argv)
{
	struct s_stack	a;
	int	n;
	char	*param;

	n = 1;
	while (n <= argc)
	{
		param = ft_strdup(argv[n]);
		n++;
	}
	return (a);
}




char	**ft_split(char const *s, char c)
{
	int		count;
	char	**array;
	int		i;

	count = split_count(s, c);
	array = init_array(s, count, c);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (array[i] != NULL)
	{
		while (*s != '\0' && *s == c)
			s++;
		ft_strlcpy(array[i], s, split_strlen(c, s) + 1);
		while (*s != '\0' && *s != c)
			s++;
		i++;
	}
	return (array);
}
