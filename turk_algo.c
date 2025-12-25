/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:55:47 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/25 17:16:41 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <limits.h>

int		turk_setup(int *stack[2], t_list *log, int *fin_sol);
void	turk_sort(int *stack[2], int *score[3], t_list *log);
void	calc_score_a(int *stack[2], int *score[3]);
void	calc_score_b(int *stack[2], int *score[3]);

int	turk_setup(int *stack[2], t_list *log, int *fin_sol)
{
	static int	score_mem = stack[1][0] * sizeof(int);
	static int	*score[3] = {malloc(score_mem), malloc(score_mem),
		malloc(score_mem)};
	
	if (!score[0] || !score[1] || !score[1])
		return (free(score[0]), free(score[1]), free(score[2]), 1);
	while (memcmp(stack[0] + 1, fin_sol, stack[0] * sizeof(int)))
	{
		ft_bzero(score[0], score_mem * sizeof(int));
		ft_bzero(score[1], score_mem * sizeof(int));
		ft_bzero(score[2], score_mem * sizeof(int));
		turk_sort(stack, score, log);
	}
	return (free(score[0]), free(score[1]), free(score[2]), 0);
}

void	turk_sort(int *stack[2], int *score[3], t_list *log)
{
	int	lowest;
	int	index;
	int	pos;

	calc_score_a(stack, score);
	calc_score_b(stack, score);
	index = 1;
	lowest = INT_MAX;
	while (index < stack[1][0] + 1)
	{
		if (score[0][index] <= lowest)
		{
			lowest = score[0][index];
			pos = index;	
		}
	}
	//TBD
	shift_to_a(stack[1][index + 1], stack, score, log);
}

void	calc_score_a(int *stack[2], int *score[3])
{
	int	index[2];

	index[0] = 0;
	while (index[0] < stack[1][0])
	{
		index[1] = 0;
		while (stack[0][index[1] + 1] < stack[1][index[0] + 1])
			index[1]++;
		if (score[1] = (index[1] > stack[0] - index[1]))
			score[0] += stack[0] - index[1] + 1;
		else
			score[0] += index[1];
		index[0]++;
	}
}

void	calc_score_b(int *stack[2], int *score[3])
{
	int	index;

	index = 0;
	while (index < stack[1][0])
	{
		if (score[2] = (index > stack[1] - index))
			score[0] += stack[1] - index + 1;
		else
			score[0] += index;
		index;
	}
}
