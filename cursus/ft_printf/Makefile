# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 14:58:42 by odemirel          #+#    #+#              #
#    Updated: 2022/03/29 15:21:36 by odemirel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(shell find . -type f -name "*.c")
LIB = libft.a
FLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a

all: $(NAME)

$(NAME):
#düzenle
	@gcc $(FLAGS) -c $(SRCS) -I.
	@ar rcs $(NAME) *.o
	@echo "\033[1;32m╔════════════════════════════════════════╗"
	@echo "\033[1;32m║        ⫷ OBJELER TEMIZLENDI!⫸          ║"
	@echo "\033[1;32m╚════════════════════════════════════════╝"

clean:
	@rm -f *.o
	@echo "\033[1;34m╔════════════════════════════════════════╗"
	@echo "\033[1;34m║        ••⁌OBJELER TEMIZLENDI!⁍••       ║"
	@echo "\033[1;34m╚════════════════════════════════════════╝"
fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;31m╔════════════════════════════════════════╗"
	@echo "\033[1;31m║         ••⁌LIB TEMIZLENDI!⁍••          ║"
	@echo "\033[1;31m╚════════════════════════════════════════╝"

re: fclean all
	
.PHONY: all $(NAME) fclean clean re