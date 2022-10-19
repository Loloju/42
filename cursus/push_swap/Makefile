# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 12:06:55 by odemirel          #+#    #+#              #
#    Updated: 2022/10/19 12:11:45 by odemirel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = $(shell find . -type f -name "*.c")
FLAGS = -Wall -Werror -Wextra
OBJS = $(SRCS:%.c=%.o)
CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	@gcc $(FLAGS) $(OBJS) -I. -o $(NAME)
	@echo "\033[32:1mPushSwap Compiled!"

re: fclean all

clean:
	@rm -rf *.o
	@echo "\033[36:1mPushSwap Clean!"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[35:1mPushSwap Fclean!"

.PHONY: all re clean fclean $(NAME)
