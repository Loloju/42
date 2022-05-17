# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/19 14:29:32 by odemirel          #+#    #+#              #
#    Updated: 2022/05/17 10:28:31 by odemirel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client/client.c
SERVER = server/server.c
LIB = ./ft_printf/libftprintf.a
FLAGS = -Wall -Werror -Wextra
NAME_CL = oclient
NAME_SV = oserver


all: $(NAME_CL) $(NAME_SV)

$(NAME_CL): prereq
	@gcc $(FLAGS) -o $@ $(CLIENT) $(LIB) -I.
	@echo "\033[32;5mClient Built!\033[0m"

$(NAME_SV):	prereq
	@gcc $(FLAGS) -o $@ $(SERVER) $(LIB) -I.
	@echo "\033[32;5mServer Built!\033[0m"

prereq:
	@make -C ft_printf

clean:
	@make fclean -C ft_printf
	@echo "\033[1;34mClean"
	
fclean: clean
	@rm -f oserver oclient
	@echo "Fclean"

re: fclean all
	
.PHONY: all $(NAME) fclean clean re