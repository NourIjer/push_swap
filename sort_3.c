/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nijer <nijer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:40:06 by nijer             #+#    #+#             */
/*   Updated: 2024/07/05 18:08:30 by nijer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void sort_3(t_node **stack_a)
{
    int a = (*stack_a)->num;
    int b = (*stack_a)->next->num;
    int c = (*stack_a)->next->next->num;

    if (a > b && b < c && a < c)
        sa(stack_a);
    else if (a > b && b > c)
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if (a > b && b < c && a > c)
        ra(stack_a);
    else if (a < b && b > c && a < c)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (a < b && b > c && a > c)
        rra(stack_a);
}
void sort_4(t_node **stack_a, t_node **stack_b)
{
    int i = 0;
    int j = 0;
    while(stack_a && i <= 4)
    {
        if(((*stack_a)->index == 0 || (*stack_a)->index == 1) && j <= 1)
        {
            pb(stack_a,stack_b);
            j++;
        }
        else
            ra(stack_a);
        i++;
    }
    if(!is_sorted(*stack_a))
        sa(stack_a);
    if(is_sorted(*stack_b))
        sb(stack_b);
    pa(stack_b,stack_a);
    pa(stack_b,stack_a);
}
void sort_5(t_node **stack_a, t_node **stack_b)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(stack_a && i <= 4)
    {
        if(((*stack_a)->index == 0 || (*stack_a)->index == 1) && j <= 1)
        {
            pb(stack_a,stack_b);
            j++;
        }
        else
            ra(stack_a);
        i++;
    }
    sort_3(stack_a);
    if(is_sorted(*stack_b))
        sb(stack_b);
    pa(stack_b,stack_a);
    pa(stack_b,stack_a);
}
