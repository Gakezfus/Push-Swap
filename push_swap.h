
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// from process_log.c
int		process_log(char **to_return, t_list *log);

// from actions.c
int	act(int *stack[2], int act_no, t_list **log);

// from actions_utils.c
void	push(int *stack[2], int src, int dest);
void	rot(int *stack, int order);
void	swap_int(int *a, int *b);

// from setup.c
int		check(char *argv[]);
int		digit_check(char *s);
int		con_int(int item_count, char *argv[], int *data);

// from merge_sort.c
void	merge_sort(int *data, int len);
int		check_sorted(int *data, int len);

#endif
