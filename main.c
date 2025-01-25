/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:36:25 by akwadran          #+#    #+#             */
/*   Updated: 2025/01/25 20:25:27 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     main(int argc, char **argv)
{
        t_stack *a;
        t_stack *b;
        char    **args_array;
        char    *aux[] = {"11", "12", "13", "14", NULL};
        
        a = NULL;
        b = NULL;
        args_array = format_arguments(argc, argv);
        a = init_stack(args_array, argc);
        b = init_stack(aux, 3);
        print_stack(a);
        print_stack(b);
        sa(&a);
        print_stack(a);
        pb(&a, &b);
        print_stack(a);
        print_stack(b);
        rrr(&a, &b);
        print_stack(a);
        print_stack(b);
        rb(&b);
        print_stack(b);
        free_stack(a);
        free_stack(b);
        return (0);
}