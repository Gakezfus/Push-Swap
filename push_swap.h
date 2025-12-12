
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

int		check(char *argv[]);
int		digit_check(char *s);
int		con_int(int argc, char *argv[], int *data);
char	*solve(int *data, int len);
void	merge_sort(int *data, int len);
int		check_sorted(int *data, int len);
void	act(char *stack[2], int act_no);
int		arrange_init(int init[4], int *stack[2], int len);

#endif
