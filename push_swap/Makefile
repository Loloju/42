# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:40:49 by odemirel          #+#    #+#              #
#    Updated: 2022/10/24 16:40:49 by odemirel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
NAME	= push_swap
FLAGS	= -Wall -Wextra -Werror
SRCS	= $(wildcard src/*.c Libft/*.c)

OBJ		= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

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

.PHONY: all re clean fclean norm