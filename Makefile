# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/11 12:05:07 by Elkan Choo        #+#    #+#              #
#    Updated: 2025/12/23 03:48:58 by Elkan Choo       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = actions.c actions_utils.c brute_sort.c init_a_to_b.c main.c \
merge_sort.c post_processing.c process_log.c setup.c turk_algo.c turk_b_to_a.c

OBJECTS = $(SOURCES:%.c=%.o)

LIBFT = libft/libft.a

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -Ilibft -g

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS) push_swap.h
	cc $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c
	cc $(CFLAGS) -MMD -MP -c $< -o $@ 

-include $(SRC:.c=.d)

clean:
	rm -f $(OBJECTS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
