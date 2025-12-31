/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:45:56 by elkan             #+#    #+#             */
/*   Updated: 2025/12/31 12:17:48 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker_bonus.h"

void	swap_int(int *a, int *b);
void	rot(int *stack, int order);
void	push(int *stack[2], int src, int dst);

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
