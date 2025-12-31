/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:11:27 by elkan             #+#    #+#             */
/*   Updated: 2025/12/31 12:36:50 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "checker_bonus.h"

static int	check_sol(int *data, int len, int *sol);
static int	find_sol(int *sol, int *data, int len);

int	main(int argc, char *argv[])
{
	int			*data;
	int			invalid;
	static int	*sol = NULL;

	if (argc < 2)
		return (1);
	data = malloc((argc) * sizeof(int));
	if (data == NULL || check(argv + 1) || con_int(argc - 1, argv + 1, data))
		return (free(data), write(2, "Error\n", 6), 1);
	sol = malloc((argc - 1) * sizeof(int));
	invalid = check_sol(data, argc - 1, sol);
	if (invalid)
		return (free(sol), free(data), write(2, "Error\n", 6), 1);
	if (!ft_memcmp(sol, data + 1, (argc - 1) * sizeof(int)))
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	return (free(sol), free(data), 0);
}

static int	check_sol(int *data, int len, int *sol)
{
	int		*stack[2];
	char	*line;

	stack[1] = ft_calloc((len + 1), sizeof(int));
	if (stack[1] == NULL || sol == NULL || find_sol(sol, data, len))
		return (free(sol), 1);
	stack[0] = data;
	ft_memmove(stack[0] + 1, stack[0], len * sizeof(int));
	stack[0][0] = len;
	line = get_next_line(0);
	while (line)
	{
		if (track_act(line, stack))
			return (free(stack[1]), 1);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (free(stack[1]), 0);
}

static int	find_sol(int *sol, int *data, int len)
{
	ft_memmove(sol, data, len * sizeof(int));
	merge_sort(sol, len);
	if (check_sorted(sol, len))
		return (1);
	return (0);
}
