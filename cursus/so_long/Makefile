# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 10:16:38 by odemirel          #+#    #+#              #
#    Updated: 2022/08/10 12:39:08 by odemirel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
MLX = MiniLibX/
LIB = ft_printf/
FLAGS = -Wall -Werror -Wextra
OPENGLFLAGS = -framework OpenGL -framework AppKit -L./minilibx -lmlx
SRCS = srcs/* ft_printf/libftprintf.a

all: $(NAME)

$(NAME):
	@make -C $(LIB)
	@gcc $(FLAGS) $(OPENGLFLAGS) $(SRCS) so_long.h -g
	@mv a.out so_long
	@echo "\033[36;5m\tSo_long Compiled!\033[0m"

re: fclean all

clean:
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