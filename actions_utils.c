/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:52:42 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/26 14:59:29 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdio.h>

// If order == 0, normal, if order == 1, reverse rotate
void	rot(int *stack, int order)
{
	int	tmp;

	tmp = stack[1];
	if (order)
		tmp = stack[stack[0]];
	if (!order)
	{
		ft_memmove(stack + 1, stack + 2, (stack[0] - 1) * sizeof(int));
		stack[stack[0]] = tmp;
	}
	else
	{
		ft_memmove(stack + 2, stack + 1, (stack[0] - 1) * sizeof(int));
		stack[1] = tmp;
	}
}

void	push(int *stack[2], int src, int dst)
{
	ft_memmove(stack[dst] + 2, stack[dst] + 1, stack[dst][0]++ * sizeof(int));
	stack[dst][1] = stack[src][1];
	ft_memmove(stack[src] + 1, stack[src] + 2, --stack[src][0] * sizeof(int));
}

void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
