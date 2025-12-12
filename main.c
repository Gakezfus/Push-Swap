/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:49:27 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/12 04:53:44 by Elkan Choo       ###   ########.fr       */
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
	write(1, "Success\n", 8);
}

void	solve(int *data, int len)
{
	int	*solution;

	solution = malloc(len * sizeof(int));
	if (solution == NULL)
		return (NULL);
	ft_memmove(solution, data, len);
	merge_sort(solution, argc - 1);
	if (!check_sorted(solution, argc - 1))
		return (free(solution), write(2, "Error\n", 6), 1);
	//TODO: initialise variables (must later create var to track state as well)
}
