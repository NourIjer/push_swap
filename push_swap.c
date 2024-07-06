/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nijer <nijer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 02:57:18 by nijer             #+#    #+#             */
/*   Updated: 2024/07/05 14:30:34 by nijer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>


int   is_sorted(t_node *head)
{
    t_node *current = head;
    while (current && current->next)
    {
        if (current->num > current->next->num)
            return (0);
        current = current->next;
    }
    return (1);
}
void free_stack(t_node **stack)
{
    t_node    *current;
    t_node    *next;

    if (stack == NULL || *stack == NULL)
        return;
    current = *stack;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *stack = NULL;
}

int     check_dup(int num, t_node **stack)
{
    t_node *current = *stack;
    while (current)
    {

        if (current->num == num)
        {
            free_stack(stack);
            write(1, "Error\n", 7);
            exit(0);
        }
        current = current->next;
    }
    return (0);
}

int     update_sign(char c, int sign)
{
    if (c == '-')
        sign = -1;
    return (sign);
}
t_node *push_numbers(t_node **stack_a, char *argv)
{
    int i;
    int sign;
    int num;

    i = 0;
    sign = 1;
    while (argv[i])
    {
        if (argv[i] == ' ')
            i++;
        if (is_operator(argv[i]))
            sign = update_sign(argv[i++], sign);
        if (is_digit(argv[i]))
        {
            num = process_number(argv, &i, &sign, stack_a);
            if (!check_dup(num, stack_a))
                ft_lst_add_back(stack_a, ft_new_node(stack_a, num));
            else
                free_stack(stack_a);
        }
        sign = 1;
    }
    return (*stack_a);
}

int main(int argc, char **argv)
{
    int i = 1;
    t_node *stack_a = NULL;
    t_node *stack_b = NULL;
    if(argc < 2)
    {
        write(1, "Error\n", 7);
        exit(0);
    }
    while (argv[i] != NULL)
    {
        if(is_empty(argv[i]) || !is_valid(argv[i]))
        {
            write(1, "Error\n", 7);
            if(stack_a)
                free_stack(&stack_a);
            exit(0);
        }
        else
            push_numbers(&stack_a, argv[i]);
        i++;
    }
    update_indices(stack_a);
    if(is_sorted(stack_a))
    {
        free_stack(&stack_a);
        return (0);
    }
	sort_stack(&stack_a,&stack_b);
}