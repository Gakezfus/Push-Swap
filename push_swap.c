/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:49:27 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/27 16:27:22 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "push_swap.h"

#include <stdio.h>

static char	*solve(int *data, int len);
static int	init_var(int *solution, int *stack[2], t_list **log);
static int	arrange_init(int init[INIT_LEN], int *stack[2],
				t_list **log, int *sol);
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
	if (!check_sorted(data, argc - 1))
		return (free(data), 0);
	to_write = solve(data, argc - 1);
	if (to_write == NULL)
		return (free(data), write(2, "Error\n", 6), 1);
	if (*to_write == 0)
		return (free(data), free(to_write), 0);
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
	int				*sol;
	int				*stack[2];
	char			*to_return;
	static t_list	*log = NULL;

	sol = malloc(len * sizeof(int));
	stack[1] = ft_calloc((len + 1), sizeof(int));
	if (stack[1] == NULL || sol == NULL || find_sol(sol, data, len))
		return (free(sol), NULL);
	stack[0] = data;
	ft_memmove(stack[0] + 1, stack[0], len * sizeof(int));
	stack[0][0] = len;
	to_return = NULL;
	log = NULL;
	if (init_var(sol, stack, &log) || brute_sort(stack, &log)
		|| turk_setup(stack, &log, len) || process_log(&to_return, log))
		return (free(sol), free(stack[1]), ft_lstclear(&log, free), NULL);
	return (free(sol), free(stack[1]), ft_lstclear(&log, free), to_return);
}

static int	find_sol(int *sol, int *data, int len)
{
	ft_memmove(sol, data, len * sizeof(int));
	merge_sort(sol, len);
	if (check_sorted(sol, len))
		return (1);
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
	if (stack[0][0] > INIT_LEN)
		if (arrange_init(init, stack, log, solution))
			return (1);
	return (0);
}

// Function is supposed to keep the 4 in stack A, send the rest to stack B,
// then sort stack A.
static int	arrange_init(int init[INIT_LEN], int *stack[2],
					t_list **log, int *sol)
{
	int	index;

	index = 0;
	while (index < 2)
	{
		if (a_to_b(sol, stack, init, log))
			return (1);
		index++;
	}
	return (0);
}
