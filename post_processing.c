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

void	update(int *path, int *dup, int c_index, int *p_index);
int		math(int act);

// indexes[0] represents the index of path, indexes[1] is used to search the
// number of consecutive actions in a row, indexesp[2] is used to store the
// value of the initial consecutive actions
void	post_processing(int *path, int *dup, int int_len)
{
	static int	indexes[3];

	while (indexes[0] < int_len)
	{
		indexes[2] = 0;
		indexes[1] = 0;
		if (5 <= path[indexes[0]] && path[indexes[0]] < 8)
		{
			while (path[indexes[0]] == path[indexes[0] + indexes[1]])
				indexes[1]++;
			indexes[2] = indexes[1];
			indexes[1] = 0;
			// When encountering 6665, indexes[1] == 1, so 66 will be replace by 10, causing bug. 
			while (indexes[1] < indexes[2] &&
					(math(path[indexes[0]]) == path[indexes[0] + indexes[2] + indexes[1]]))
				indexes[1]++;
			// indexes[1] represents the number of "in a rows" that can be
			// replaced by rr or rrr. If 0, just copy over. Otherwise,
			// add the appropriate elements to dup and move indexes[0] accordingly
		}
		update(path, dup, indexes[1], &indexes[0]);
	}
	// for (int i = 0; i < int_len; i++)
	// {
	// 	printf("dup[%i]: %i\n", i, dup[i]);
	// }
}

void	update(int *path, int *dup, int c_index, int *p_index)
{
	static int	dup_index = 0;
	int			rr_act;
	int			index;

	if (!c_index)
		dup[dup_index++] = path[(*p_index)++];
	else
	{
		rr_act = 10;
		if (path[*p_index] >= 7)
			rr_act = 11;
		index = 0;
		while (index++ < c_index)
		{
			dup[dup_index] = rr_act;
			dup_index++;
			*p_index += 2;
		}
	}
}

// If the action is 5 or 7, it will be odd and will += 1.
// If even, it will be even and -= 1;
// odd will be 1 for odd and 0 for even numbers.
// even will be 1 for even and 0 for odd numbers. 
int	math(int act)
{
	int odd;
	int	even;
	
	odd = act % 2;
	even = (1 - act % 2);
	act += odd - even;
	return (act);
}
