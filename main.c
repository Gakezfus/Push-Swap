/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:49:27 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/11 18:54:58 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include <stdio.h>

int				error_check(char *argv[]);
int				digit_check(char *s);
int				process_int(int argc, char *argv[], int *data);
long long int	ft_atoll(const char *str);
void			merge_sort(int *data, int len);

int	main(int argc, char *argv[])
{
	int	*data;

	data = malloc((argc - 1) * sizeof(int));
	if (data == NULL)
		return (write(2, "Error\n", 6), 1);
	if (argc < 2)
		return (1);
	if (error_check(argv + 1))
		return (write(2, "Error\n", 6), 1);
	if (process_int(argc - 1, argv + 1, data))
		return (write(2, "Error\n", 6), 1);
	merge_sort(data, argc - 1);
	for (int i = 0; i < argc - 1; i++)
	{
		printf("%i\n", data[i]);
	}
	write(1, "Success\n", 8);
}

int	error_check(char *argv[])
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
int	process_int(int item_count, char *argv[], int *data)
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

long long int	ft_atoll(const char *str)
{
	int				negative;
	int				index;
	long long int	to_return;

	negative = -1;
	index = 0;
	while (str[index] == ' ' || ('\t' <= str[index] && str[index] <= '\r'))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
		{
			negative = -negative;
		}
		index++;
	}
	to_return = 0;
	while (('0' <= str[index] && str[index] <= '9'))
	{
		to_return *= 10;
		to_return -= str[index] - '0';
		index++;
	}
	to_return *= negative;
	return (to_return);
}
