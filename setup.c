/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:55:37 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/24 10:55:41 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "libft.h"
#include "push_swap.h"

int	check(char *argv[])
{
	int	index;
	int	index2;

	index = 0;
	while (argv[index])
	{
		if (digit_check(argv[index]))
			return (1);
		index2 = 0;
		while (index2 < index)
		{
			if (!ft_strncmp(argv[index], argv[index2], 10))
				return (1);
			index2++;
		}
		index++;
	}
	return (0);
}

int	digit_check(char *s)
{
	int	index;

	index = 0;
	while (s[index])
	{
		if (index == 0 && s[index] == '-' && s[index + 1])
			(void) 0;
		else if (!ft_isdigit(s[index]))
			return (1);
		index++;
	}
	return (0);
}

// Converts the string into ints, and checks for overflows.
int	con_int(int item_count, char *argv[], int *data)
{
	int				index;
	long long int	check;

	index = 0;
	while (index < item_count)
	{
		check = ft_atoll(argv[index]);
		if (check < INT_MIN || INT_MAX < check)
			return (1);
		data[index] = (int)check;
		index++;
	}
	return (0);
}
