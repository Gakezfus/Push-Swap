
// act_no == 1:
// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one element or none.

// act_no == 2:
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one element or none.

// act_no == 3;
// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.

// act_no == 4:
// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.

// act_no == 5:
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.

// act_no == 6:
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.

// act_no == 7:
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.

// act_no == 8:
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.

// act_no == 9;
// ss: sa and sb at the same time.

// act_no == 10;
// rr: ra and rb at the same time.

// act_no == 11;
// rrr : rra and rrb at the same time.

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "push_swap.h"

int	act(int *stack[2], int act_no, t_list **log);
int	log_act(int act_no, t_list **log);

static void	act_2(int *stack[2], int act_no, t_list **log);

int	act(int *stack[2], int act_no, t_list **log)
{
	if (act_no == 1)
		swap_int(&stack[0][1], &stack[0][2]);
	if (act_no == 2)
		swap_int(&stack[1][1], &stack[1][2]);
	if (act_no == 3)
		push(stack, 1, 0);
	if (act_no == 4)
		push(stack, 0, 1);
	if (act_no == 5)
		rot(stack[0], 0);
	if (act_no == 6)
		rot(stack[1], 0);
	if (act_no == 7)
		rot(stack[0], 1);
	if (act_no == 8)
		rot(stack[0], 1);
	if (act_no >= 9)
		act_2(stack, act_no, log);
	//TODO Function
	if (log_act(act_no, log))
		return (1);
	return (0);
}

static void	act_2(int *stack[2], int act_no, t_list **log)
{
	if (act_no == 9)
	{
		swap_int(&stack[0][1], &stack[0][2]);
		swap_int(&stack[1][1], &stack[1][2]);
		log_act(act_no, log);
	}
	if (act_no == 10)
	{
		rot(stack[0], 0);
		rot(stack[1], 0);
		log_act(act_no, log);
	}
	if (act_no == 11)
	{
		rot(stack[0], 1);
		rot(stack[1], 1);
		log_act(act_no, log);
	}
}

int	log_act(int act_no, t_list **log)
{
	t_list	*new;
	int		*cont;

	new = malloc(sizeof(t_list));
	cont = malloc(sizeof(int));
	if (cont == NULL || new == NULL)
		return (ft_lstclear(log, free), 1);
	*cont = act_no;
	new->content = cont;
	new->next = NULL;
	ft_lstadd_back(log, new);
	return (0);
}
