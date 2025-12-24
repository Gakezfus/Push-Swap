/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:52:17 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/24 14:12:36 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "push_swap.h"

// TODO: test the search
static int	*search(int *stack, int *sol, int *path, int *depth);
static int	*search_2(int *stack, int *sol, int *path, int *depth);

int	brute_sort(int *stack[2], t_list **log)
{
	static int	*path = NULL;
	int			*p_dup;
	int			*sol;
	static int	index = 1;
	static int	depth[1] = {1};

	sol = malloc(INIT_LEN * sizeof(int));
	ft_memcpy(sol, stack[0] + 1, INIT_LEN * sizeof(int));
	merge_sort(sol, INIT_LEN);
	p_dup = malloc(sizeof(int));
	if (p_dup == NULL)
		return (1);
	p_dup[0] = 0;
	while (!path && depth[0]++)
		path = search(stack[0], sol, p_dup, depth);
	printf("sol_len: %i\n", *path);
	while (index < path[0] + 1)
	{
		if (act("157"[path[index] - 1] - '0', stack, log))
			return (free(p_dup), free (sol), 1);
		index++;
	}
	return (free(p_dup), free (sol), free(path), 0);
}

static int	*search(int *stack, int *sol, int *path, int *depth)
{
	int	*ret;
	int	*p_dup;

	if (!ft_memcmp(stack + 1, sol, INIT_LEN * sizeof(int)))
		return (path);
	path[0]++;
	if (path[0] > *depth)
		return (path[0]--, NULL);
	p_dup = malloc((path[0] + 2) * sizeof(int));
	if (p_dup == NULL || !ft_memcpy(p_dup, path, path[0] * sizeof(int)))
		return (path[0]--, free(p_dup), NULL);
	ret = search_2(stack, sol, p_dup, depth);
	if (ret)
		return (path[0]--, ret);
	return (path[0]--, NULL);
}

// Returns path if solution found, NULL if no solution found or mem error.
// Memory errors are detected by setting depth to 0.
static int	*search_2(int *stack, int *sol, int *path, int *depth)
{
	int	index;
	int	*ret;
	int	*s_dup;

	s_dup = malloc((stack[0] + 1) * sizeof(int));
	if (s_dup == NULL)
		return (free(s_dup), free(path), *depth = 0, NULL);
	index = 1;
	while(*depth && index < 4)
	{
		ft_memcpy(s_dup, stack, (stack[0] + 1) * sizeof(int));
		path[path[0]] = index;
		act_a(index, s_dup);
		if (!ft_memcmp(s_dup + 1, sol, INIT_LEN * sizeof(int)))
			return (free(s_dup), path);
		ret = search(s_dup, sol, path, depth);
		if (ret)
			return (free(s_dup), free(path), ret);
		index++;
	}
	return (free(s_dup), free(path), NULL);
}
