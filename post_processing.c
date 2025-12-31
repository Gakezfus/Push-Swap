/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 09:38:47 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/27 16:33:19 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "push_swap.h"

void	update(int *path, int *dup, int indexes[3]);
int		math(int act);

// indexes[0] represents the index of path, indexes[1] is used to search the
// number of consecutive actions in a row, indexesp[2] is used to store the
// value of the initial consecutive actions
void	post_processing(int *path, int *dup, int int_len)
{
	static int	ind[3];

	while (ind[0] < int_len)
	{
		ind[2] = 0;
		ind[1] = 0;
		if (5 <= path[ind[0]] && path[ind[0]] <= 8)
		{
			while (ind[0] + ind[1] < int_len && path[ind[0]]
				== path[ind[0] + ind[1]])
			{
				ind[1]++;
			}
			ind[2] = ind[1];
			ind[1] = 0;
			while (ind[0] + ind[2] + ind[1] < int_len && ind[1] < ind[2]
				&& (math(path[ind[0]]) == path[ind[0] + ind[2] + ind[1]]))
				ind[1]++;
		}
		update(path, dup, ind);
	}
}

void	update(int *path, int *dup, int indexes[3])
{
	static int	dup_index = 0;
	int			rr_act;
	int			index;

	if (!indexes[1])
		dup[dup_index++] = path[indexes[0]++];
	else
	{
		rr_act = 10;
		if (path[indexes[0]] >= 7)
			rr_act = 11;
		index = 0;
		while (index++ < indexes[2] - indexes[1])
			dup[dup_index++] = path[indexes[0]++];
		index = 0;
		while (index++ < indexes[1])
		{
			dup[dup_index] = rr_act;
			dup_index++;
			indexes[0] += 2;
		}
	}
}

// If the action is 5 or 7, it will be odd and will += 1.
// If even, it will be even and -= 1;
// odd will be 1 for odd and 0 for even numbers.
// even will be 1 for even and 0 for odd numbers. 
int	math(int act)
{
	int	odd;
	int	even;

	odd = act % 2;
	even = (1 - act % 2);
	act += odd - even;
	return (act);
}
