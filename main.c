/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:49:27 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/22 14:49:09 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "push_swap.h"

#include <stdio.h>

char	*solve(int *data, int len);
int	init_var(int *solution, int *stack[2], t_list **log);
int	arrange_init(int init[4], int *stack[2], int len, t_list **log);

int	main(int argc, char *argv[])
{
	int		*data;
	char	*to_write;

	if (argc < 2)
		return (1);
	data = malloc((argc) * sizeof(int));
	if (data == NULL || check(argv + 1) || con_int(argc - 1, argv + 1, data))
		return (free(data), write(2, "Error\n", 6), 1);
	to_write = solve(data, argc - 1);
	if (to_write == NULL)
		return (free(data), write(2, "Error\n", 6), 1);
	//TODO: Add printf to libft
	//ft_printf("%s\n", to_write);
	write(1, "Success\n", 8);
}

// stack[0] represents stack A, stack[1] represents stack B
// stack[0][0] stores the len of stack A, stack[1][0] stores the len
// of stack B
char	*solve(int *data, int len)
{
	int		*sol;
	int		*stack[2];
	char	*to_return;
	t_list	*log;

	stack[0] = data;
	ft_memmove(stack[0] + 1, stack[0], len)
	stack[0][0] = len;
	stack[1] = calloc((len + 1) * sizeof(int));
	sol = malloc(len * sizeof(int));
	if (stack[1] == NULL || sol == NULL)
		return (NULL);
	if (find_sol(sol, data, len) || init_var(sol, stack, &log))
		return (free(sol), write(2, "Error\n", 6), NULL);
	// The initialisation must be tested first, as well as the log
}

// PUT ON HOLD
int	turk_algo(int *stack[2], t_list *log, int *sol)
{
	int	scores[2];
	int	index;

	while (ft_memcmp(&stack[0][1], sol))
	index = 0;
	while (index < stack[0][0])
		ft_memmove(scores[index], stack[0][index + 1])
}

int	find_sol(int *sol, int *data, int len)
{
	ft_memmove(sol, data, len);
	merge_sort(sol, len);
	if (check_sorted(sol, argc - 1))
		return (free(sol), write(2, "Error\n", 6), 1);
	return (0);
}

int	init_var(int *solution, int *stack[2], t_list **log,)
{
	int	init[4];
	int	index;

	index = 0;
	while (index < 4 && index < stack[0][0])
		init[index] = stack[0][(stack[0][0] / 2) + 1 + index++];
	if (arrange_init(init, stack, len, log))
		return (1);
	return (0);
}

// Function is supposed to keep the 4 in stack A, send the rest to stack B, then sort stack A. Function is WIP,
// necessary to finish the actions function first in actions.c
int	arrange_init(int init[4], int *stack[2], t_list **log)
{
	int	index;

	while (index < len)
	{
		if (ft_memchr(init, stack[0][index], 4 * sizeof(int)))
		{
			if (act(stack, 5, log));
				return (1);
		}
		else
			if (act(stack, 4, log));
				return (1); 
	}
	return (0);
}
