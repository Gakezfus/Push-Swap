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

SOURCES = actions.c actions_utils.c brute_sort.c init_a_to_b.c push_swap.c \
merge_sort.c post_processing.c process_log.c setup.c turk_algo.c turk_b_to_a.c

BONUS_SOURCES = $(wildcard *_bonus.c)

OBJECTS = $(SOURCES:%.c=%.o)

BONUS_OBJECTS = $(BONUS_SOURCES:%.c=%.o)

LIBFT = libft/libft.a

NAME = push_swap

BONUS_NAME = checker

CFLAGS = -Wall -Wextra -Werror -Ilibft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS) push_swap.h
	cc $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJECTS) checker_bonus.h
	cc $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
	make -C libft

%.o: %.c
	cc $(CFLAGS) -MMD -MP -c $< -o $@ 

-include $(SRC:.c=.d)

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)
	make clean -C libft

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	rm -f $(SOURCES:%.c=%.d)
	rm -f $(BONUS_SOURCES:%.c=%.d)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re bonus
