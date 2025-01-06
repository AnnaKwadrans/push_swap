/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:22:11 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/06 16:24:51 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include "Libft/libft.h"

/*
typedef struct	s_stack
{
	int	num;
	struct s_stack	*next;
}	t_list;
*/

char	**format_arguments(int argc, char** argv);
void	print_array(char **args_array); //quitar
t_list	*init_list(char **args_array);
void	print_list(t_list *stack);

#endif
