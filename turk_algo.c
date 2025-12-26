/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:55:47 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/26 15:37:01 by Elkan Choo       ###   ########.fr       */
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

int	turk_setup(int *stack[2], t_list **log, int sol_len)
{
	int	*score[3];
	int	score_mem;

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
	return (free(score[0]), free(score[1]), free(score[2]), 0);
}

int	turk_sort(int *stack[2], int *score[3], t_list **log)
{
	int	lowest;
	int	index;
	int	pos;

	calc_score_a(stack, score);
	calc_score_b(stack, score);
	printf("stack[0] len: %i\n", stack[0][0]);
	for (int i = 0; i < stack[0][0]; i++)
	{
		printf("stack[0][%i]: %i\n", i + 1, stack[0][i + 1]);
	}
	printf("\n");
	printf("stack[1] len: %i\n", stack[1][0]);
	for (int i = 0; i < stack[1][0]; i++)
	{
		printf("stack[1][%i]: %i, score[0]: %i, score[1]: %i, score[2]: %i\n", i + 1, stack[1][i + 1], score[0][i], score[1][i],  score[2][i]);
	}
	printf("\n\n");
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

void	calc_score_a(int *stack[2], int *score[3])
{
	int	index[2];

	index[0] = 0;
	while (index[0] < stack[1][0])
	{
		index[1] = 0;
		while (stack[0][index[1] + 1] < stack[1][index[0] + 1]
				&& index[1] < stack[0][0] - 1)
			index[1]++;
		score[1][index[0]] = index[1] > stack[0][0] - index[1];
		if (score[1][index[0]])
			score[0][index[0]] += stack[0][0] - index[1];
		else
			score[0][index[0]] += index[1];
		index[0]++;
	}
}

void	calc_score_b(int *stack[2], int *score[3])
{
	int	index;

	index = 0;
	while (index < stack[1][0])
	{
		score[2][index] = index > stack[1][0] - index;
		if (score[2][index])
			score[0][index] += stack[1][0] - index;
		else
			score[0][index] += index;
		index++;
	}
}
