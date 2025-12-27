/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 02:03:28 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/27 03:49:48 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

#include <stdio.h>

int			shift_to_a(int pos, int *stack[2], int *score[3], t_list **log);
static int	b_to_a(int pos, int *stack[2], int rev, t_list **log);

int	shift_to_a(int sc_index, int *stack[2], int *score[3], t_list **log)
{
	int	element;
	int	pos;

	element = stack[1][sc_index + 1];
	pos = check_order_in_stack(stack[0], element);
	while (stack[1][1] != element)
	{
		if (act(6 + (score[2][sc_index]) * 2, stack, log))
			return (1);
	}
	// for (int i = 0; i < stack[0][0] + 1; i++)
	// {
	// 	printf("stack[0][%i]: %i\n", i, stack[0][i]);
	// }
	// for (int i = 0; i < stack[1][0] + 1; i++)
	// {
	// 	printf("stack[1][%i]: %i\n", i, stack[1][i]);
	// }
	// printf("\n");
	// printf("rev: %i\n", score[1][sc_index]);
	// printf("element: %i\n", element);
	// printf("ori_index: %i\n\n", pos);
	if (score[1][sc_index])
		pos = stack[0][0] - pos;
	if (b_to_a(pos, stack, score[1][sc_index], log))
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
	return (0);
}
