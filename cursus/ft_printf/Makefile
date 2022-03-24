# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 14:58:42 by odemirel          #+#    #+#              #
#    Updated: 2022/03/24 16:02:37 by odemirel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(shell find . -type f -name "*.c")
LIB = libft.a
FLAGS = -Wall -Werror -Wextra
NAME = main.out

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRCS) $(LIB) -o $(NAME)
	@echo "\n\033[1;34m-=<Compiled!>=-\n"

clean:
	@rm -f $(NAME)
	@echo "\n\033[1;34m••⁌OUT CLEANED!⁍••\n"

.PHONY: all $(NAME) clean