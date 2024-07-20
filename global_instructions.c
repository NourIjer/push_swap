/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nijer <nijer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:35:01 by nijer             #+#    #+#             */
/*   Updated: 2024/07/19 01:01:21 by nijer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*push(int index, int num, t_node **stack_head)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		free(stack_head);
		return (NULL);
	}
	new_node->num = num;
	new_node->index = index;
	new_node->next = *stack_head;
	*stack_head = new_node;
	return (new_node);
}

int	pop(t_node **stack_head)
{
	int		num;
	t_node	*tmp;

	if (!*stack_head)
		return (-1);
	num = (*stack_head)->num;
	tmp = *stack_head;
	*stack_head = (*stack_head)->next;
	free (tmp);
	tmp = NULL;
	return (num);
}

void	swap(t_node **stack)
{
	t_node	*second;
	t_node	*first;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	(*stack)->next = second->next;
	second->next = first;
	*stack = second;
}

void	rrotate(t_node **stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	if (second_last)
		second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rotate(t_node **stack)
{
	t_node	*head;
	t_node	*tail;

	head = *stack;
	tail = lstlast(head);
	if (head == tail)
		return ;
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
}
