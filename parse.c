/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nijer <nijer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:23:13 by nijer             #+#    #+#             */
/*   Updated: 2024/07/20 06:37:59 by nijer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_operator(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!is_digit(str[i]) && !is_operator(str[i])
			&& str[i] != ' ' && str[i] != '\0')
			return (0);
		else if (is_operator(str[i]) && !is_digit(str[i + 1]))
			return (0);
		else if (is_digit(str[i]) && str[i + 1]
			&& !is_digit(str[i + 1]) && str[i + 1] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	is_empty(char *argv)
{
	int	j;
	int	k;

	k = 0;
	j = 0;
	if (argv[0] == '\0')
		return (1);
	while (argv[j] != '\0')
	{
		if (is_digit(argv[j]))
			k++;
		j++;
	}
	if (!k)
		return (1);
	return (0);
}
