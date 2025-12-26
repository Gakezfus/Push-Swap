/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 02:03:28 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/26 19:55:53 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

#include <stdio.h>

int			shift_to_a(int pos, int *stack[2], int *score[3], t_list **log);
static int	b_to_a(int pos, int *stack[2], int rev, t_list **log);

int	shift_to_a(int pos, int *stack[2], int *score[3], t_list **log)
{
	int	element;
	int	index;

	element = stack[1][pos + 1];
	while (stack[1][1] != element)
	{
		if (act(6 + (score[2][pos]) * 2, stack, log))
			return (1);
	}
	index = 0;
	while (element > stack[0][index + 1] && index < stack[0][0])
		index++;
	if (score[1][pos])
		index = stack[0][0] - index - 1;
	if (b_to_a(index, stack, score[1][pos], log))
		return (1);
	return (0);
}

int	b_to_a(int pos, int *stack[2], int rev, t_list **log)
{
	int	index;

	index = 0;
	while (index < pos)
	{
		if (act(5 + rev * 2, stack, log))
			return (1);
		index++;
	}
	if (act(3, stack, log))
		return (1);
	index = 0;
	while (index < pos + rev)
	{
		if (act(7 - rev * 2, stack, log))
			return (1);
		index++;
	}
	return (0);
}
