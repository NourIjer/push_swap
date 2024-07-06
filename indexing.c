/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nijer <nijer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 07:59:42 by nijer             #+#    #+#             */
/*   Updated: 2024/06/10 04:46:49 by nijer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_size(t_node *head)
{
    int size = 0;
    t_node *current = head;
    while (current != NULL)
    {
        size++;
        current = current->next;
    }
    return size;
}
