/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:49:27 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/12 11:00:31 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "push_swap.h"

#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		*data;
	char	*to_write;

	if (argc < 2)
		return (1);
	data = malloc((argc - 1) * sizeof(int));
	if (data == NULL || check(argv + 1) || con_int(argc - 1, argv + 1, data))
		return (free(data), write(2, "Error\n", 6), 1);
	to_write = solve(data, argc - 1);
	if (to_write == NULL)
		return (free(data), write(2, "Error\n", 6), 1);
	//TODO: Add printf to libft
	//ft_printf("%s\n", to_write);
	write(1, "Success\n", 8);
}

char	*solve(int *data, int len)
{
	int		*solution;
	char	*to_return;

	solution = malloc(len * sizeof(int));
	if (solution == NULL)
		return (NULL);
	ft_memmove(solution, data, len);
	// The merge sort and following sorted check might be better at other parts
	merge_sort(solution, argc - 1);
	if (!check_sorted(solution, argc - 1))
		return (free(solution), write(2, "Error\n", 6), NULL);
	to_return = init_var(solution, data, len);
}

//TODO: initialise variables (must later create var to track state as well)

// stack[0] represents stack A, stack[1] represents stack B
char	*init_var(int *solution, int *data, int *len)
{
	int	*stack[2];
	int	init[4];
	int	index;

	stack[0] = data;
	stack[1] = calloc(len * sizeof(int));
	if (stack[1] == NULL)
		return (NULL);
	index = 0;
	while (index < 4 && index < len)
		init[index] = data[(len * 4 )/ 5 + index++];
	if (arrange_init(init, stack, len))
		return (NULL);
}

// Function is supposed to keep the 4 in stack A, send the rest to stack B, then sort stack A. Function is WIP,
// necessary to finish the actions function first in actions.c
int	arrange_init(int init[4], int *stack[2], int len)
{
	int	index;

	while (index < len)
	{
		if (ft_memchr(init, stack[0][index], 4 * sizeof(int)))
			// Make action for the act
			act(stack, act_no, len);
	}
}
