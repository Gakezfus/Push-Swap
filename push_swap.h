/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:52:51 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/26 15:35:24 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define INIT_LEN 4

// from process_log.c
int		process_log(char **to_return, t_list *log);

// from actions.c
int		act(int act_no, int *stack[2], t_list **log);
int		act_a(int act_no, int *stack);

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

// from brute_sort.c
int		brute_sort(int *stack[2], t_list **log);

// from turk_algo.c
int		turk_setup(int *stack[2], t_list **log, int sol_len);

// from turk_b_to_a.c
int		shift_to_a(int pos, int *stack[2], int *score[3], t_list **log);

#endif
