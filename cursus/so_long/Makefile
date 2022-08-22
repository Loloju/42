# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 10:16:38 by odemirel          #+#    #+#              #
#    Updated: 2022/08/22 10:54:04 by odemirel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
MLX = MiniLibX/
LIB = ft_printf/
GNL = ../get_next_line/*.c
FLAGS = -Wall -Werror -Wextra
OPENGLFLAGS = -framework OpenGL -framework AppKit -L./minilibx -lmlx
SRCS = srcs/* ft_printf/libftprintf.a

all: minilib $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(GNL)
	@ar rcs gnlft.a *.o
	@rm *.o

	@make -C $(LIB)
	@gcc $(FLAGS) $(OPENGLFLAGS) $(SRCS) $(GNL) -I. -g -o $(NAME)
	@echo "\033[36;5m\tSo_long Compiled!\033[0m"

re: fclean all

clean: mclean
	@make fclean -C $(LIB)
	@echo "\033[35;5m\tSo_long Clean!\033[0m"
fclean: clean
	@rm -rf so_long
	@echo "Complete Wipe!"

minilib:
	@make -C $(MLX)

mclean:
	@make clean -C $(MLX)

.PHONY: all re clean fclean minilib mclean $(NAME)