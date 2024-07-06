/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nijer <nijer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 03:19:43 by nijer             #+#    #+#             */
/*   Updated: 2024/06/09 05:43:58 by nijer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ss(t_node **stack_a, t_node **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    write(1,"ss",2);
}

void    rr(t_node **stack_a, t_node **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    write(1,"rr",2);
}

void    rrr(t_node **stack_a, t_node **stack_b)
{
    rrotate(stack_a);
    rrotate(stack_b);
    write(1,"rrr",3);
}