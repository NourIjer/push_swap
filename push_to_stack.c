/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nijer <nijer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 02:49:34 by nijer             #+#    #+#             */
/*   Updated: 2024/07/04 18:55:20 by nijer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void update_indices(t_node *head)
{
    t_node *current = head;
    t_node *compare;
    
    while (current != NULL)
    {
        int index = 0;
        compare = head;
        while (compare != NULL)
        {
            if (compare->num < current->num)
            {
                index++;
            }
            compare = compare->next;
        }
        current->index = index;
        current = current->next;
    }
}
void	ft_lst_add_back(t_node **stack, t_node *stack_new)
{
    t_node	*tmp;

    if (*stack == NULL)
    {
        *stack = stack_new;
        return ;
    }
    tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = stack_new;
}
t_node    *ft_new_node(t_node **stack, int num)
{
    t_node    *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    if (new_node == NULL)
    {
        free_stack(stack);
        write(1, "Error\n", 7);
        exit(0);
    }
    new_node->num = num;
    new_node->next = NULL;
    return (new_node);
}

int     process_number(char *argv, int *i, int *sign, t_node **stack)
{
    unsigned long num;

    num = 0;
    while (is_digit(argv[*i]))
    {
        num = num * 10 + argv[*i] - '0';
        *i += 1;
        if(num > 2147483647 && *sign == 1)
        {
            write(1, "Error\n", 7);
            if(stack_size(*stack) > 0)
                free_stack(stack);
            exit(0);
        }
        if(num > 2147483648 && *sign == -1)
        {
            write(1, "Error\n", 7);
            if(stack_size(*stack) > 0)
                free_stack(stack);
            exit(0);
        }
    }
    return ((int)num * (*sign));
}
