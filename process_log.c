
#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "push_swap.h"

static int	log_len(t_list *log);
static void	convert(char **to_return, t_list *log);

int	process_log(char **to_return, t_list *log)
{
	int	len;

	len = log_len(log);
	*to_return = malloc((len + 1));
	if (*to_return == NULL)
		return (ft_lstclear(&log, free), 1);
	convert(to_return, log);
	// potentially process to_return to check for double action efficiency.
	// will see if such efficiency is necessary. If necessary, will prob
	// want to create an array of ints representing each action as a num.
	return (0);
}

// If this is not norm, I think I need a new function. Ridiculous.
// strlcpy null terminates, so values are one larger
static void	convert(char **to_return, t_list *log)
{
	t_list	*tmp;
	int		index;

	index = 0;
	tmp = log;
	while (tmp)
	{
		if (*(int*)(tmp->content) == 1)
			ft_strlcpy(*to_return + index, "sa\n", 4);
		if (*(int*)(tmp->content) == 2)
			ft_strlcpy(*to_return + index, "sb\n", 4);
		if (*(int*)(tmp->content) == 3)
			ft_strlcpy(*to_return + index, "pb\n", 4);
		if (*(int*)(tmp->content) == 4)
			ft_strlcpy(*to_return + index, "pb\n", 4);
		if (*(int*)(tmp->content) == 5)
			ft_strlcpy(*to_return + index, "ra\n", 4);
		if (*(int*)(tmp->content) == 6)
			ft_strlcpy(*to_return + index, "rb\n", 4);
		if (*(int*)(tmp->content) == 7)
			ft_strlcpy(*to_return + index++, "rra\n", 5);
		if (*(int*)(tmp->content) == 8)
			ft_strlcpy(*to_return + index++, "rrb\n", 5);
		index += 3;
		tmp = tmp->next;
	}
}

static int	log_len(t_list *log)
{
	int		len;
	t_list	*tmp;

	tmp = log;
	len = 0;
	while (tmp)
	{
		if (*(int*)(tmp->content) <= 6 || *(int*)(tmp->content) == 9 ||
		*(int*)(tmp->content) == 10)
			len += 3;
		else
			len += 4;
		tmp = tmp->next;
	}
	return (len);
}
