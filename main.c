/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:49:27 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/24 14:12:37 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "libft.h"
#include "push_swap.h"

#include <stdio.h>

static char	*solve(int *data, int len);
static int	init_var(int *solution, int *stack[2], t_list **log);
static int	arrange_init(int init[INIT_LEN], int *stack[2], t_list **log);
static int	find_sol(int *sol, int *data, int len);

int	main(int argc, char *argv[])
{
	int		*data;
	char	*to_write;
	int		index;

	if (argc < 2)
		return (1);
	data = malloc((argc) * sizeof(int));
	if (data == NULL || check(argv + 1) || con_int(argc - 1, argv + 1, data))
		return (free(data), write(2, "Error\n", 6), 1);
	to_write = solve(data, argc - 1);
	if (to_write == NULL)
		return (free(data), write(2, "Error\n", 6), 1);
	//TODO: Add printf to libft
	index = 0;
	while (to_write[index])
		write(1, to_write + index++, 1);
	return (free(data), free(to_write), 0);
}

// stack[0] represents stack A, stack[1] represents stack B
// stack[0][0] stores the len of stack A, stack[1][0] stores the len
// of stack B
static char	*solve(int *data, int len)
{
	int		*sol;
	int		*stack[2];
	char	*to_return;
	t_list	*log;

	sol = malloc(len * sizeof(int));
	stack[1] = ft_calloc((len + 1), sizeof(int));
	if (stack[1] == NULL || sol == NULL)
		return (NULL);
	find_sol(sol, data, len);
	stack[0] = data;
	ft_memmove(stack[0] + 1, stack[0], len * sizeof(int));
	stack[0][0] = len;
	to_return = NULL;
	log = NULL;
	if (init_var(sol, stack, &log) ||
	brute_sort(stack, &log) ||
	process_log(&to_return, log))
		return (free(sol), free(stack[1]), ft_lstclear(&log, free), NULL);
	for (int i = 0; i < stack[0][0] + 1; i++)
	{
		printf("stack[%i]: %i\n", i, stack[0][i]);
	}
	// TODO: Brute sort (goes before Turk algo)
	// TODO: Turk algo before process_log.
	return (free(sol), free(stack[1]), ft_lstclear(&log, free), to_return);
}

static int	find_sol(int *sol, int *data, int len)
{
	ft_memmove(sol, data, len * sizeof(int));
	merge_sort(sol, len);
	if (check_sorted(sol, len))
		return (free(sol), 1);
	return (0);
}

static int	init_var(int *solution, int *stack[2], t_list **log)
{
	int	init[INIT_LEN];
	int	index;

	index = 0;
	if (stack[0][0] >= INIT_LEN)
	{
		while (index < INIT_LEN)
		{
			if (stack[0][0] / 2 >= INIT_LEN)
				init[index] = solution[(stack[0][0] / 2) + index - 1];
			else
				init[index] = solution[stack[0][0] - index - 1];
			index++;	
		}
	}
	if (stack[0][0] >= INIT_LEN)
		if (arrange_init(init, stack, log))
			return (1);
	return (0);
}

// Function is supposed to keep the 4 in stack A, send the rest to stack B,
// then sort stack A. Function is WIP, necessary to finish the actions
// function first in actions.c
static int	arrange_init(int init[INIT_LEN], int *stack[2], t_list **log)
{
	int	index;
	int	len;
	int	*stack_1;

	index = 0;
	len = stack[0][0];
	stack_1 = malloc(len * sizeof(int));
	if (stack_1 == NULL)
		return (free(stack_1), 1);
	ft_memcpy(stack_1, stack[0] + 1, len * sizeof(int));
	while (index < len)
	{
		if (ft_memchr(init, stack_1[index++],
			INIT_LEN * sizeof(int)))
		{
			if (act(5, stack, log))
				return (free(stack_1), 1);
		}
		else
			if (act(4, stack, log))
				return (free(stack_1), 1);
	}
	return (free(stack_1), 0);
}
