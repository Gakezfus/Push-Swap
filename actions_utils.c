
#include "libft.h"

// If order == 0, normal, if order == 1, reverse rotate
void	rot(char *stack, int order)
{
	int	tmp;

	tmp = stack[0];
	if (order)
		tmp = stack[stack[0] - 1];
	if (order)
	{
		ft_memmove(stack + 1, stack + 2, stack[0]);
		stack[stack[0] - 1] = tmp;
	}
	else
	{
		ft_memmove(stack + 2, stack + 1, stack[0]);
		stack[1] = tmp;
	}
}

void	push(char *stack[2], int src, int dest)
{git 
	ft_memmove(stack[dest] + 2, stack[dest] + 1, stack[dest][0]++);
	stack[dest][1] = stack[src][1];
	ft_memmove(stack[src] + 1, stack[src] + 2, --stack[src][0]);
}

void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
