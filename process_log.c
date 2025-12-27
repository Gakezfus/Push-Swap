/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_log.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:52:29 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/27 10:09:15 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "push_swap.h"

static int	log_len(t_list *log, int *int_len);
static void	convert_log(char **to_return, int *path, int len);
static void log_to_int(int *path, t_list *log);

// potentially process to_return to check for double action efficiency.
// will see if such efficiency is necessary. If necessary, will prob
// want to create an array of ints representing each action as a num.
int	process_log(char **to_return, t_list *log)
{
	int			str_len;
	static int	int_len = 0;
	int			*path;
	int			*dup;

	if (log == NULL)
		return (*to_return = malloc(sizeof(int)), **to_return = 0, 0);
	str_len = log_len(log, &int_len);
	*to_return = malloc((str_len + 1));
	path = malloc(int_len * sizeof(int));
	dup = malloc(int_len * sizeof(int));
	if (*to_return == NULL || path == NULL || dup == NULL)
		return (ft_lstclear(&log, free), 1);
	log_to_int(path, log);
	post_processing(path, dup, int_len);
	// free(path);
	// path = dup;
	convert_log(to_return, path, int_len);
	return (0);
}

static void log_to_int(int *path, t_list *log)
{
	t_list		*tmp;
	static int	index = 0;
	tmp = log;
	while (tmp)
	{
		path[index] = *(int *)(tmp->content);
		index++;
		tmp = tmp->next;
	}
}

// If this is not norm, I think I need a new function. Ridiculous.
// strlcpy null terminates, so values are one larger
static void	convert_log(char **to_return, int *path, int len)
{
	static int	str_index = 0;
	static int	path_index = 0;

	while (path_index < len)
	{
		if (path[path_index] == 1)
			ft_strlcpy(*to_return + str_index, "sa\n", 4);
		if (path[path_index] == 2)
			ft_strlcpy(*to_return + str_index, "sb\n", 4);
		if (path[path_index] == 3)
			ft_strlcpy(*to_return + str_index, "pa\n", 4);
		if (path[path_index] == 4)
			ft_strlcpy(*to_return + str_index, "pb\n", 4);
		if (path[path_index] == 5)
			ft_strlcpy(*to_return + str_index, "ra\n", 4);
		if (path[path_index] == 6)
			ft_strlcpy(*to_return + str_index, "rb\n", 4);
		if (path[path_index] == 7)
			ft_strlcpy(*to_return + str_index++, "rra\n", 5);
		if (path[path_index] == 8)
			ft_strlcpy(*to_return + str_index++, "rrb\n", 5);
		path_index++;
		str_index += 3;
	}
}

static int	log_len(t_list *log, int *int_len)
{
	int		len;
	t_list	*tmp;

	tmp = log;
	len = 0;
	while (tmp)
	{
		if (*(int *)(tmp->content) <= 6 || *(int *)(tmp->content) == 9 ||
		*(int *)(tmp->content) == 10)
			len += 3;
		else
			len += 4;
		tmp = tmp->next;
		(*int_len)++;
	}
	return (len);
}
