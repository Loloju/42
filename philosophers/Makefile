# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odemirel <odemirel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 12:30:07 by odemirel          #+#    #+#              #
#    Updated: 2022/11/29 10:57:15 by odemirel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
NAME	= philosophers
CFLAGS	= -Wall -Wextra -Werror
SRCS	= $(wildcard *.c)

OBJ		= $(SRCS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

re: fclean all

clean:
	@rm -rf $(OBJ)

fclean:	clean
	@rm -rf $(NAME)
	@echo "silindi!"

norm:
	@norminette $(wildcard src/*.c)
	@norminette $(wildcard inc/*.h)
	@norminette $(wildcard Libft/*.c)

.PHONY: all re clean fclean norm