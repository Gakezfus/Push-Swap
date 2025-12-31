/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:55:47 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/27 03:49:42 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

#include <stdio.h>

int			turk_setup(int *stack[2], t_list **log, int sol_len);
static int	turk_sort(int *stack[2], int *score[3], t_list **log);
static void	calc_score_a(int *stack[2], int *score[3]);
static void	calc_score_b(int *stack[2], int *score[3]);
int			check_order_in_stack(int *stack, int sortee);

int	turk_setup(int *stack[2], t_list **log, int sol_len)
{
	int	*score[3];
	int	score_mem;
	int	to_rra;

	score_mem = stack[1][0] * sizeof(int);
	score[0] = malloc(score_mem);
	score[1] = malloc(score_mem);
	score[2] = malloc(score_mem);
	if (!score[0] || !score[1] || !score[1])
		return (free(score[0]), free(score[1]), free(score[2]), 1);
	while (!(stack[0][0] == sol_len))
	{
		ft_bzero(score[0], stack[1][0] * sizeof(int));
		ft_bzero(score[1], stack[1][0] * sizeof(int));
		ft_bzero(score[2], stack[1][0] * sizeof(int));
		if (turk_sort(stack, score, log))
			return (free(score[0]), free(score[1]), free(score[2]), 1);
	}
	to_rra = check_rra(stack[0]);
	while (check_sorted(stack[0] + 1, stack[0][0]))
		act(5 + 2 * to_rra, stack, log);
	return (free(score[0]), free(score[1]), free(score[2]), 0);
}

int	turk_sort(int *stack[2], int *score[3], t_list **log)
{
	int	lowest;
	int	index;
	int	pos;

	calc_score_a(stack, score);
	calc_score_b(stack, score);
	index = 0;
	lowest = INT_MAX;
	while (index < stack[1][0])
	{
		if (score[0][index] <= lowest)
		{
			lowest = score[0][index];
			pos = index;
		}
		index++;
	}
	if (shift_to_a(pos, stack, score, log))
		return (1);
	return (0);
}

int	check_order_in_stack(int *stack, int sortee)
{
	int	index;
	int	pos;
	int	largest;

	index = -1;
	while (++index < stack[0])
	{
		if (index == 0)
			if (stack[stack[0]] < sortee && sortee < stack[1])
				return (index);
		if (index > 0 && stack[index] < sortee && sortee < stack[index + 1])
			return (index);
	}
	ft_set_zero(2, &index, &pos);
	largest = INT_MIN;
	while (++index < stack[0] + 1)
	{
		if (stack[index] > largest)
		{
			largest = stack[index];
			pos = index - 1;
		}
	}
	return (pos + 1);
}

void	calc_score_a(int *stack[2], int *score[3])
{
	int	index;
	int	pos;

	index = 0;
	while (index < stack[1][0])
	{
		pos = check_order_in_stack(stack[0], stack[1][index + 1]);
		score[1][index] = pos > stack[0][0] - pos;
		if (score[1][index])
			score[0][index] += stack[0][0] - pos;
		else
			score[0][index] += pos;
		index++;
	}
}

void	calc_score_b(int *stack[2], int *score[3])
{
	int	index;
	int	diff;
	int	to_add;

	index = 0;
	diff = score[0][index];
	while (index < stack[1][0])
	{
		diff = score[0][index];
		score[2][index] = index > stack[1][0] - index;
		if (score[2][index])
			to_add = stack[1][0] - index;
		else
			to_add = index;
		score[0][index] += to_add;
		if (diff > to_add)
			diff = to_add;
		if (score[1][index] == score[2][index])
			score[0][index] -= diff;
		index++;
	}
}
