/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nijer <nijer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 02:44:35 by nijer             #+#    #+#             */
/*   Updated: 2024/07/15 00:14:22 by nijer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_node
{
	int				index;
	int				num;
	struct s_node	*next;
}	t_node;

void	sort_4(t_node **stack_a, t_node **stack_b);
void	sort_5(t_node **stack_a, t_node **stack_b);
int		is_sorted(t_node *head);
void	sort_2(t_node **stack_a);
void	sort_3(t_node **stack_a);
int		top(t_node *stack, int size);
void	push_to_b(t_node **stack_a, t_node **stack_b);
void	push_to_a(t_node **stack_a, t_node **stack_b);
void	sort_stack(t_node **stack_a, t_node **stack_b);
void	ft_lst_add_back(t_node **stack, t_node *stack_new);
t_node	*ft_new_node(t_node **stack, int num);
int		stack_size(t_node *head);
void	update_indices(t_node *head);
void	free_stack(t_node **stack);
int		check_dup(int num, t_node **stack);
int		is_digit(char c);
int		is_operator(char c);
int		is_valid(char *str);
int		is_empty(char *argv);
int		update_sign(char c, int sign);
int		process_number(char *argv, int *i, int *sign, t_node **stack);
t_node	*push_numbers(t_node **stack_a, char *argv);
t_node	*push(int index, int num, t_node **stack_head);
int		pop(t_node **stack_head);
void	swap(t_node **stack);
void	rotate(t_node **stack);
void	rrotate(t_node **stack);
void	pa(t_node **stack_b, t_node **stack_a);
void	pb(t_node **stack_a, t_node **stack_b);
void	sa(t_node **stack_a);
void	ra(t_node **stack_a);
void	rra(t_node **stack_a);
void	sb(t_node **stack_b);
void	rb(t_node **stack_b);
void	rrb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
t_node	*lstlast(t_node *head);
void	error(t_node **stack);

#endif