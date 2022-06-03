# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 10:16:38 by odemirel          #+#    #+#              #
#    Updated: 2022/05/30 17:13:30 by odemirel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIB = get_next_line/
MLX = MiniLibX/
FLAGS = -Wall -Werror -Wextra
OPENGLFLAGS = -framework OpenGL -framework AppKit -L./minilibx -lmlx

all: $(NAME)

$(NAME):
	@make -C $(LIB)
	@mv get_next_line/getnextline.a .
	@gcc $(FLAGS) $(OPENGLFLAGS) getnextline.a so_long.c so_long.h
	@mv a.out so_long
	@echo "\033[36;5m\tSo_long Compiled!\033[0m"

re: fclean all

clean:
	@make fclean -C $(LIB)
	@echo "\033[35;5m\tSo_long Clean!\033[0m"

fclean: clean

minilib:
	@make -C $(MLX)

mclean:
	@make clean -C $(MLX)

.PHONY: all re clean fclean minilib mclean $(NAME)