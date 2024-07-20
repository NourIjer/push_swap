/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nijer <nijer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 00:57:05 by nijer             #+#    #+#             */
/*   Updated: 2024/07/20 06:05:20 by nijer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lstlast(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->next)
			tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

int	stack_size(t_node *head)
{
	int		size;
	t_node	*current;

	size = 0;
	current = head;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*next;

	if (stack == NULL || *stack == NULL)
		return ;
	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	error(t_node **stack_a)
{
	write(2, "Error\n", 6);
	if (*stack_a)
		free_stack(stack_a);
	exit(1);
}
