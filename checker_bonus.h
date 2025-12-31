/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 12:18:31 by elkan             #+#    #+#             */
/*   Updated: 2025/12/31 12:18:35 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

// from setup_bonus.c
int		check(char *argv[]);
int		digit_check(char *s);
int		con_int(int item_count, char *argv[], int *data);

// from actions_bonus.c
int		track_act(char *s, int *stack[2]);
void	act(int act_no, int *stack[2]);

// from actions_utils.c
void	swap_int(int *a, int *b);
void	rot(int *stack, int order);
void	push(int *stack[2], int src, int dst);

// from merge_sort.c
int		check_sorted(int *data, int len);
void	merge_sort(int *data, int len);

#endif
