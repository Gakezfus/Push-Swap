
// act_no = 1:
// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one element or none.

// act_no = 2:
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one element or none.

// act_no = 3;
// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.

// act_no = 4:
// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.

// act_no = 5:
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.

// act_no = 6:
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.

// act_no = 7:
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.

// act_no = 8:
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.

#include "libft.h"
#include "push_swap.h"
#include <stddef.h>

void	act(char *stack[2], int act_no, int len)
{
	if (act_no == 1)
		swap_int(&stack[0][0], &stack[0][1]);
	if (act_no == 2)
		swap_int(&stack[1][0], &stack[1][1]);
	if (act_no == 3)
	{
		// Might want to compress this into a function
		ft_memmove(stack[0] + 1, stack[0], len - 1);
		stack[0][0] = stack[1][0];
		ft_memmove(stack[1], stack[1] + 1, len - 1);
	}
}

void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = a;
}
