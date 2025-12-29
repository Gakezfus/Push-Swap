/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 12:15:31 by elkan             #+#    #+#             */
/*   Updated: 2025/12/29 19:52:07 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "push_swap.h"

int	a_to_b(int *stack_1, int *stack[2], int init[INIT_LEN], t_list **log);
int	*make_chunk(int *stack[2], int *chunk);
int *get_longest_chunk(int *stack[2], int* c_data[3]);

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
	chunk = get_longest_chunk(stack, c_data);
	return (free(c_data[0]), free(c_data[1]), free(c_data[2]), chunk);
}

int *get_longest_chunk(int *stack[2], int* c_data[3])
{
	int			len;
	int			longest_index;
	int			longest_len;
	static int	index[2];

	len = stack[0][0];
	while (index[0] < len)
	{
		ft_set_zero(3, &longest_len, &longest_index, &index[1]);
		while (index[1] < index[0])
		{
			if (ft_idim(c_data[0][index[0]], c_data[0][index[1]]) <= 2)
			{
				if (c_data[1][index[1]] > longest_len)
				{
					longest_len = c_data[1][index[1]];
					longest_index = c_data[2][index[1]];
				}
			}
			index[1]++;
		}
		c_data[1][index[0]] = longest_len + 1;
		index[0]++;
	}
	return (NULL);
}
