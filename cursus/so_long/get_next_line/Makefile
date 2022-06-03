# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 10:40:13 by odemirel          #+#    #+#              #
#    Updated: 2022/05/27 09:58:19 by odemirel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c *.c -I.
	@ar rcs $(NAME) *.o
	@echo "\033[32;5m\tGNL Compiled.\033[0m"

clean:
	@rm -rf *.o
	@echo "\033[34;5m\tGNL Clean.\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[35;5m\tGNL Fclean.\033[0m"

re: fclean all

.PHONY: all re clean fclean $(NAME)