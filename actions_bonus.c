/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:16:06 by elkan             #+#    #+#             */
/*   Updated: 2025/12/31 12:17:38 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "libft.h"

int			track_act(char *s, int *stack[2]);
void		act(int act_no, int *stack[2]);
static void	act_2(int act_no, int *stack[2]);

int	track_act(char *s, int *stack[2])
{
	if (!ft_strncmp(s, "sa\n", 4))
		return (act(1, stack), 0);
	else if (!ft_strncmp(s, "sb\n", 4))
		return (act(2, stack), 0);
	else if (!ft_strncmp(s, "pa\n", 4))
		return (act(3, stack), 0);
	else if (!ft_strncmp(s, "pb\n", 4))
		return (act(4, stack), 0);
	else if (!ft_strncmp(s, "ra\n", 4))
		return (act(5, stack), 0);
	else if (!ft_strncmp(s, "rb\n", 4))
		return (act(6, stack), 0);
	else if (!ft_strncmp(s, "rra\n", 5))
		return (act(7, stack), 0);
	else if (!ft_strncmp(s, "rrb\n", 5))
		return (act(8, stack), 0);
	else if (!ft_strncmp(s, "ss\n", 5))
		return (act(9, stack), 0);
	else if (!ft_strncmp(s, "rr\n", 5))
		return (act(10, stack), 0);
	else if (!ft_strncmp(s, "rrr\n", 5))
		return (act(11, stack), 0);
	return (1);
}

// act_no == 1:
// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one element or none.

// act_no == 2:
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one element or none.

// act_no == 3;
// pa (push a): Take the first element at the top of b and put it
// at the top of a.
// Do nothing if b is empty.

// act_no == 4:
// pb (push b): Take the first element at the top of a and put it
// at the top of b.
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

void	act(int act_no, int *stack[2])
{
	if (act_no == 1 && stack[0][0] >= 2)
		swap_int(&stack[0][1], &stack[0][2]);
	if (act_no == 2 && stack[1][0] >= 2)
		swap_int(&stack[1][1], &stack[1][2]);
	if (act_no == 3 && stack[1][0])
		push(stack, 1, 0);
	if (act_no == 4 && stack[0][0])
		push(stack, 0, 1);
	if (act_no == 5 && stack[0][0])
		rot(stack[0], 0);
	if (act_no == 6 && stack[1][0])
		rot(stack[1], 0);
	if (act_no == 7)
		rot(stack[0], 1);
	if (act_no == 8)
		rot(stack[1], 1);
	if (act_no >= 9)
		act_2(act_no, stack);
}

static void	act_2(int act_no, int *stack[2])
{
	if (act_no == 9)
	{
		swap_int(&stack[0][1], &stack[0][2]);
		swap_int(&stack[1][1], &stack[1][2]);
	}
	if (act_no == 10)
	{
		rot(stack[0], 0);
		rot(stack[1], 0);
	}
	if (act_no == 11)
	{
		rot(stack[0], 1);
		rot(stack[1], 1);
	}
}
