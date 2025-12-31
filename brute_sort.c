/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:52:17 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/27 03:26:20 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "push_swap.h"

// TODO: test the search
static int	*search(int *stack, int *sol, int *path, int *depth);
static int	*search_2(int *stack, int *sol, int *path, int *depth);

// Sol here is for the sorted order of current elements, not ALL elements
int	brute_sort(int *stack[2], t_list **log)
{
	int			*path;
	int			*sol;
	static int	*fin_path = NULL;
	static int	index = 1;
	static int	depth = 1;

	sol = malloc(stack[0][0] * sizeof(int));
	path = malloc(sizeof(int));
	if (sol == NULL || path == NULL)
		return (free(path), 1);
	ft_memcpy(sol, stack[0] + 1, stack[0][0] * sizeof(int));
	merge_sort(sol, stack[0][0]);
	path[0] = 0;
	while (!fin_path && depth++)
		fin_path = search(stack[0], sol, path, &depth);
	while (index < fin_path[0] + 1)
	{
		if (act("157"[fin_path[index] - 1] - '0', stack, log))
		{
			return (free(sol), free(path), free(fin_path), 1);
		}
		index++;
	}
	return (free(sol), free(path), free(fin_path), 0);
}

static int	*search(int *stack, int *sol, int *path, int *depth)
{
	int	*ret;
	int	*p_dup;

	p_dup = malloc((path[0] + 2) * sizeof(int));
	if (p_dup == NULL || !ft_memcpy(p_dup, path, (path[0] + 1) * sizeof(int)))
		return (NULL);
	if (!ft_memcmp(stack + 1, sol, stack[0] * sizeof(int)))
		return (p_dup);
	p_dup[0]++;
	if (p_dup[0] > *depth)
		return (free(p_dup), NULL);
	ret = search_2(stack, sol, p_dup, depth);
	return (ret);
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
	while (*depth && index < 4)
	{
		ft_memcpy(s_dup, stack, (stack[0] + 1) * sizeof(int));
		path[path[0]] = index;
		act_a(index, s_dup);
		if (!ft_memcmp(s_dup + 1, sol, s_dup[0] * sizeof(int)))
			return (free(s_dup), path);
		ret = search(s_dup, sol, path, depth);
		if (ret)
			return (free(s_dup), free(path), ret);
		index++;
	}
	return (free(s_dup), free(path), NULL);
}
