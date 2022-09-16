# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 12:06:55 by odemirel          #+#    #+#              #
#    Updated: 2022/09/15 12:25:44 by odemirel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = *.c
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRC) -I. -o $(NAME)
	@echo "\033[32:1mPushSwap Compiled!"

re: fclean all

clean:
	@rm -rf *.o
	@echo "\033[36:1mPushSwap Clean!"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[35:1mPushSwap Fclean!"

.PHONY: all re clean fclean $(NAME)
