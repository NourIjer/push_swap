/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nijer <nijer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:31:53 by nijer             #+#    #+#             */
/*   Updated: 2024/07/05 18:30:46 by nijer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	top(t_node *stack, int size)
{
	t_node	*head;
	int		i;

	head = stack;
	i = 1;
	while (stack)
	{
		if (stack->index == size)
			break ;
		i++;
		stack = stack->next;
	}
	if (i <= stack_size(stack) / 2)
		return (1);
	return (0);
}
void	push_to_b(t_node **stack_a, t_node **stack_b)
{
	int		i;

	int		x;

	x = 16;
	if (stack_size(*stack_a) > 100)
		x = 34;
	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + x)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

void	push_to_a(t_node **stack_a, t_node **stack_b)
{
	int		size;

	size = stack_size(*stack_b) - 1;
	while (*stack_b)
	{
		if ((*stack_b)->index == size)
		{
			pa(stack_b, stack_a);
			size--;
		}
		else if (top(*stack_b, size) == 1)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}
void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	if(stack_size(*stack_a) == 2)
		sa(stack_a);
	else if(stack_size(*stack_a) == 3)
		sort_3(stack_a);
	else if(stack_size(*stack_a) == 4)
		sort_4(stack_a, stack_b);
	else if(stack_size(*stack_a) == 5)
		sort_5(stack_a, stack_b);
	else
	{
		push_to_b(stack_a, stack_b);
		push_to_a(stack_a, stack_b);
	}
}
