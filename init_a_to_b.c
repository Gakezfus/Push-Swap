/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 12:15:31 by elkan             #+#    #+#             */
/*   Updated: 2025/12/29 20:57:31 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "push_swap.h"

int	a_to_b(int *stack_1, int *stack[2], int init[INIT_LEN], t_list **log);
int	*make_chunk(int *stack[2], int *chunk);
int	*get_longest_chunk(int *stack[2], int* c_data[3], int *sol);

int	a_to_b(int *stack_1, int *stack[2], int init[INIT_LEN], t_list **log)
{
	int			len;
	static int	index = 0;
	
	len = stack[0][0];
	while (index < len)
	{
		if (ft_intchr(init, stack_1[index], INIT_LEN))
		{
			if (act(5, stack, log))
				return (1);
		}
		else
			if (act(4, stack, log))
				return (1);
		index++;
	}
	return (0);
}

int	*make_chunk(int *stack[2], int *sol)
{
	int	*c_data[3];
	int	index;
	int	*chunk;

	c_data[0] = ft_calloc(stack[0][0], sizeof(int));
	c_data[1] = ft_calloc(stack[0][0], sizeof(int));
	c_data[2] = ft_calloc(stack[0][0], sizeof(int));
	if (!c_data[0] || !c_data[1] || !c_data[2])
		return (free(c_data[0]), free(c_data[1]), NULL);
	index = 0;
	while (index < stack[0][0])
	{
		c_data[0][index] = get_sol_index(stack[0][index + 1], sol);
		index++;
	}
	chunk = get_longest_chunk(stack, c_data, sol);
	return (free(c_data[0]), free(c_data[1]), free(c_data[2]), chunk);
}


// c_data[0][i] represents the order of the element stack[0][i + 1] in the
// solution. So, stack[0][1] == 0 means stack[0][2] is first in the solution
// c_data[1][i] represents the longest possible string of numbers that have
// at most a gap of 2 from neighbours (neighbour - num <= |2|) that ends at
// stack[0][i + 1]. c_data[2][i] represents the solution index of the previous
// number in that string. So, if c_data[0][c_data[2][i]] == 1, the previous
// number would be second from the top in the solution
int	*get_longest_chunk(int *stack[2], int* c_data[3], int *sol)
{
	int			longest_index;
	int			longest_len;
	static int	index[2];

	while (index[0] < stack[0][0])
	{
		ft_set_zero(3, &longest_len, &longest_index, &index[1]);
		while (index[1] < index[0])
		{
			if (ft_idim(c_data[0][index[0]], c_data[0][index[1]]) <= 2)
			{
				if (c_data[1][index[1]] > longest_len)
				{
					longest_len = c_data[1][index[1]];
					longest_index = index[1];
				}
			}
			index[1]++;
		}
		c_data[1][index[0]] = longest_len + 1;
		c_data[2][index[0]] = longest_index;
		index[0]++;
	}
	return (make_chunk(stack, c_data, sol));
}


// Code should theoretically return chunk correctly. Needs testing
int	*make_chunk(int *stack[2], int* c_data[3], int *sol)
{
	int	index;
	int	longest_len;
	int	longest_index;
	int	*chunk;

	find_chunk(&longest_len, &longest_index, stack, c_data);
	index = 0;
	chunk = malloc(longest_len * sizeof(int));
	if (chunk == NULL)
		return (NULL);
	while (c_data[1][longest_index] >= 1)
	{
		chunk[index] = sol[c_data[0][longest_index]];
		longest_index = c_data[2][longest_index];
	}
	return (chunk);
}

void	find_chunk(int *longest_len, int *longest_index, int *stack[2], int *c_data[3])
{
	int	index;

	ft_set_zero(3, longest_len, longest_index, &index);
	while (index < stack[0])
	{
		if (c_data[1][index] > *longest_len)
		{
			*longest_len = c_data[1][index];
			*longest_index = index;
		}
	}
}

