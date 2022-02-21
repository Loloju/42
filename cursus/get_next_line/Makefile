# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odemirel <odemirel@student.42kocaeli.>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 16:45:59 by odemirel          #+#    #+#              #
#    Updated: 2022/02/21 10:52:43 by odemirel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS = $(shell find . -type f -name "*.c")
CC = gcc
FLAGS = -Wall -Werror -Wextra

all:
	mkdir bin
	$(CC) $(FLAGS) $(SRCS) -o "main"

clean:
	rm -rf bin
	rm -f *.out

.PHONY: all clean
