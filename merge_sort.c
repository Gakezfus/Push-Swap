/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:46:04 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/11 19:07:17 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>
#include <string.h>

void	merge_sort(int *data, int len)
{
	int	*dup;
	int	*blk1;
	int	*blk2;
	int	index;
	int	blk1_index;
	int	blk2_index;

	dup = malloc((len) * sizeof(int));
	blk1 = data;
	blk2 = data + len/2;
	if (dup == NULL)
		return ;
	if (len > 2)
	{
		merge_sort(blk1, len/2);
		merge_sort(blk2, len - len/2);
		index = 0;
		blk1_index = 0;
		blk2_index = 0;
		while (index < len)
		{
			if (blk2_index >= len - len/2)
				dup[index++] = blk1[blk1_index++];
			if (blk1_index >= len/2)
				dup[index++] = blk2[blk2_index++];
			if (*blk1 < *blk2)
				dup[index++] = blk1[blk1_index++];
			else
				dup[index++] = blk2[blk2_index++];
		}
		ft_memmove(data, dup, len * sizeof(int));
	}
	else if (len == 2)
	{
		if (data[1] < data[0])
		{
			dup[0] = data[1];
			data[1] = data[0];
			data[0] = dup[0];
		}
	}
	free(dup);
}
