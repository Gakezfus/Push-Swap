# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/11 12:05:07 by Elkan Choo        #+#    #+#              #
#    Updated: 2025/12/11 17:45:06 by Elkan Choo       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = $(wildcard *.c)

OBJECTS = $(SOURCES:%.c=%.o)

LIBFT = libft/libft.a

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	cc $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

print:
	echo $(SOURCES)

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
