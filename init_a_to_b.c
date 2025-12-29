/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 12:15:31 by elkan             #+#    #+#             */
/*   Updated: 2025/12/29 14:08:22 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "push_swap.h"

int		a_to_b(int *stack_1, int *stack[2], int init[INIT_LEN], t_list **log);
void	make_chunk(int *stack[2], int init[INIT_LEN], int *chunk, int *sol);
int		fwd_max_len(int *stack[2], int init[INIT_LEN], int *chunk, int *sol);

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

void	make_chunk(int *stack[2], int init[INIT_LEN], int *chunk, int *sol)
{
	// static int fwd_count = fwd_max_len(stack, init, chunk, sol);
	(void)stack;
	(void)init;
	(void)chunk;
	(void)sol;
	return ;
}

// int	fwd_max_len(int *stack[2], int init[INIT_LEN], int *chunk, int *sol)
// {
// 	int	start_index;
// 	int	chunk_len;
// 	int	max_len;
// 	int	sol_index;
// 	int	stack_index;

// 	max_len = 0;
// 	start_index = 1;
// 	while (start_index < stack[0][0] + 1 - max_len
// 			&& !ft_intchr(init, stack[0][start_index], INIT_LEN))
// 	{
// 		chunk_len = 1;
// 		sol_index = get_sol_index(stack[0][start_index], sol);
// 		stack_index = start_index + 1;
// 		while (stack_index < stack[0][0])
// 		{
// 			if (ft_idim(get_sol_index(stack[0][stack_index], sol), sol_index)
// 					<= 2 && !ft_intchr(init, stack[0][stack_index], INIT_LEN))
// 				chunk_len++;
// 		}
// 		if (chunk_len > max_len)
// 			max_len = chunk_len;
// 		start_index++;
// 	}
// 	return (max_len);
// }
