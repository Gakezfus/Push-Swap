
#include "libft.h"
#include "push_swap.h"

// TODO: test the search
int	*brute_search(int *stack, int *sol)
static int	*search(int *stack, int *sol, int *path, int *depth);

int	*brute_search(int *stack, int *sol)
{
	int	*path;
	int	*depth;
	int	depth_2;
	int	*ret;

	if (ft_memcmp(stack + 1, sol, stack[0]))
		return (NULL);
	path = malloc(sizeof(int));
	path[0] = 0;
	*depth = 1;
	while (*depth)
	{
		ret = search(stack, sol, path, depth);
		if (ret)
			return (ret);
		if (depth)
			depth++;
	}
	return (NULL);
}

// Returns path if solution found, NULL if no solution found or mem error.
// Memory errors are detected by setting depth to 0.
static int	*search(int *stack, int *sol, int *path, int *depth)
{
	int	*s_dup;
	int	*p_dup;

	path[0]++;
	if (path[0] >= depth)
		return (NULL);
	if (ft_memcmp(stack + 1, sol, stack[0] * sizeof(int)))
		return (path);
	s_dup = malloc(sizeof(stack));
	if (s_dup == NULL)
		return (*depth = 0, NULL);
	p_dup = malloc(sizeof(path) + 2 * sizeof(int));
	if (p_dup == NULL || !ft_memcpy(p_dup, path, path[0] * sizeof(int)))
		return (free(s_dup), *depth = 0, NULL);
	index = 1;
	while(*depth && index < 4)
	{
		ft_memcpy(s_dup, stack + 1, stack[0] * sizeof(int));
		p_dup[path[0]] = index;
		act_a(index, s_dup);
		return_value = brute_sort(s_dup, sol, p_dup, depth)
		if (return_value)
			return (free(s_dup), free(p_dup), return_value);
	}
	return (NULL);
}
