/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_instructions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nijer <nijer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 03:11:19 by nijer             #+#    #+#             */
/*   Updated: 2024/07/13 22:06:22 by nijer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **stack_b, t_node **stack_a)
{
	if (!*stack_b)
		return ;
	push(0, pop(stack_b), stack_a);
	write(1, "pa\n", 3);
}

void	sa(t_node **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	ra(t_node **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rra(t_node **stack_a)
{
	rrotate(stack_a);
	write(1, "rra\n", 4);
}
