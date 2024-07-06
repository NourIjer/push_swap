/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_instructions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nijer <nijer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 03:11:46 by nijer             #+#    #+#             */
/*   Updated: 2024/07/04 18:05:22 by nijer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void    pb(t_node **stack_a, t_node **stack_b)
{
    push((*stack_a)->index,pop(stack_a), stack_b);
	write(1, "pb\n", 3);
}

void    sb(t_node **stack_b)
{
    swap(stack_b);
    write(1,"sb\n",3);
}

void    rb(t_node **stack_b)
{
    rotate(stack_b);
    write(1,"rb\n",3);
}

void    rrb(t_node **stack_b)
{
    rrotate(stack_b);
    write(1,"rrb\n",4);
}
