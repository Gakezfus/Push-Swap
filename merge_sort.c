/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:46:04 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/26 17:39:03 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "push_swap.h"

static void	merge(int *data, int len, int index[3]);

// Len is number of ints, not number of bytes
void	merge_sort(int *data, int len)
{
	int	tmp;
	int	index[3];

	tmp = 0;
	ft_bzero(index, 3 * sizeof(int));
	if (len > 2)
		merge(data, len, index);
	else if (len == 2)
	{
		if (data[1] < data[0])
		{
			tmp = data[1];
			data[1] = data[0];
			data[0] = tmp;
		}
	}
}

int	get_sol_index(int i, int *sol)
{
	int	index;

	index = 0;
	while (!(i == sol[index]))
		index++;
	return (index);
}

static void	merge(int *data, int len, int index[3])
{
	int	*blk1;
	int	*blk2;
	int	*dup;

	dup = malloc((len) * sizeof(int));
	if (dup == NULL)
		return ;
	blk1 = data;
	blk2 = data + len / 2;
	merge_sort(blk1, len / 2);
	merge_sort(blk2, len - len / 2);
	while (index[0] < len)
	{
		if (!(index[1] >= len / 2) && (index[2] >= len - len / 2
				|| blk1[index[1]] < blk2[index[2]]))
			dup[index[0]++] = blk1[index[1]++];
		else
			dup[index[0]++] = blk2[index[2]++];
	}
	ft_memmove(data, dup, len * sizeof(int));
	free(dup);
}

int	check_sorted(int *data, int len)
{
	int	index;

	index = 0;
	while (index < len - 1)
	{
		if (data[index] > data[index + 1])
			return (1);
		index++;
	}
	return (0);
}
