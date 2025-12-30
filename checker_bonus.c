/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:11:27 by elkan             #+#    #+#             */
/*   Updated: 2025/12/30 19:25:24 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

static char	*solve(int *data, int len);
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
	if (*to_write == 0)
		return (free(data), free(to_write), 0);
	index = 0;
	while (to_write[index])
		write(1, to_write + index++, 1);
	return (free(data), free(to_write), 0);
}

static char	*solve(int *data, int len)
{
	int		*sol;
	int		*stack[2];
	char	line[4];

	sol = malloc(len * sizeof(int));
	stack[1] = ft_calloc((len + 1), sizeof(int));
	if (stack[1] == NULL || sol == NULL || find_sol(sol, data, len))
		return (free(sol), NULL);
	stack[0] = data;
	ft_memmove(stack[0] + 1, stack[0], len * sizeof(int));
	stack[0][0] = len;
	line = get_next_line(0);
	while(!line)
	{
		(other stuff)
		line = get_next_line(0);
	}
}

static int	find_sol(int *sol, int *data, int len)
{
	ft_memmove(sol, data, len * sizeof(int));
	merge_sort(sol, len);
	if (check_sorted(sol, len))
		return (1);
	return (0);
}
