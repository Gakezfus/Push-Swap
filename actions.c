
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
// sa and sb at the same time.

// act_no == 10;
// ra and rb at the same time.

// act_no == 11;
// rrr : rra and rrb at the same time.

#include "libft.h"
#include "push_swap.h"
#include <stddef.h>
#include <stdlib.h>

int	act(char *stack[2], int act_no, t_list **log);
int	act_2(char *stack[2], int act_no, t_list **log);
int	log_act(int act_no, t_list **log);
void	push(char *stack[2], src, dest);
void	rot(char *stack, order);
void	swap_int(int *a, int *b);

int	act(char *stack[2], int act_no, t_list **log)
{
	if (act_no == 1)
		swap_int(&stack[0][1], &stack[0][2]);
	if (act_no == 2)
		swap_int(&stack[1][1], &stack[1][2]);
	if (act_no == 3)
		push(stack, 0, 1);
	if (act_no == 4)
		push(stack, 1, 0);
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
		return (0);
	return (1);
}

int	log_act(int act_no, t_list **log);
{
	t_list	*new;
	int		cont;

	cont = malloc(sizeof(int));
	if (cont == NULL)
		return (ft_lstclear(log, free_cont), 1);
	*cont = *act_no;
	new->content = cont;
	ft_lstadd_back(log, new);
	return (0);
}

void	free_cont(void *cont)
{
	free(cont);
}

void	act_2(char *stack[2], int act_no, t_list log)
{
	if (act_no == 9)
	{
		swap_int(&stack[0][1], &stack[0][2]);
		swap_int(&stack[1][1], &stack[1][2]);
		log_act(act_no, t_list log);
	}
	if (act_no == 10)
	{
		rot(stack[0], 0);
		rot(stack[1], 0);
		log_act(act_no, t_list log);
	}
	if (act_no == 11)
	{
		rot(stack[0], 1);
		rot(stack[1], 1);
		log_act(act_no, t_list log);
	}
}

// If order == 0, normal, if order == 1, reverse rotate
void	rot(char *stack, order)
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

void	push(char *stack[2], src, dest)
{
	ft_memmove(stack[dest] + 2, stack[dest] + 1, stack[dest][0]++);
	stack[dest][1] = stack[src][1];
	ft_memmove(stack[src] + 1, stack[src] + 2, --stack[src][0]);
}

void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = a;
}
