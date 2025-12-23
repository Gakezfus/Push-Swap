
#include <stdlib.h>

#include "libft.h"

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
	to_return[len] = '\0';
	// potentially process to_return to check for double action efficiency.
	// will see if such efficiency is necessary. If necessary, will prob
	// want to create an array of ints representing each action as a num.
	return (0);
}

// If this is not norm, I think I need a new function. Ridiculous.
static void	convert(char **to_return, t_list *log)
{
	t_list	*tmp;
	int		index;

	index = 0;
	tmp = log;
	while (tmp)
	{
		if (*(int*)(tmp->content) == 1)
			ft_strlcpy(*to_return + index, "sa\n", 3);
		if (*(int*)(tmp->content) == 2)
			ft_strlcpy(*to_return + index, "sb\n", 3);
		if (*(int*)(tmp->content) == 2)
			ft_strlcpy(*to_return + index, "pb\n", 3);
		if (*(int*)(tmp->content) == 2)
			ft_strlcpy(*to_return + index, "pb\n", 3);
		if (*(int*)(tmp->content) == 2)
			ft_strlcpy(*to_return + index, "ra\n", 3);
		if (*(int*)(tmp->content) == 2)
			ft_strlcpy(*to_return + index, "rb\n", 3);
		if (*(int*)(tmp->content) == 2)
			ft_strlcpy(*to_return + index++, "rra\n", 4);
		if (*(int*)(tmp->content) == 2)
			ft_strlcpy(*to_return + index++, "rrb\n", 4);
		index += 3;
		tmp = tmp->next;
	}
}

static int	log_len(t_list *log)
{
	int		len;
	t_list	*tmp;

	tmp = log;
	while (tmp)
	{
		if (*(int*)(tmp->content) <= 6 || *(int*)(tmp->content) == 9 ||
		*(int*)(tmp->content) == 10)
			len += 3;
		else
			len += 4;
	}
	tmp = tmp->next;
	return (len);
}
