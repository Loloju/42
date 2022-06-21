# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 10:16:38 by odemirel          #+#    #+#              #
#    Updated: 2022/06/21 15:36:18 by odemirel         ###   ########.fr        #
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
	@gcc $(FLAGS) $(OPENGLFLAGS) so_long.c get_line.c ../libft/ft_strjoin.c ../libft/ft_strlen.c ../libft/ft_strchr.c so_long.h -g
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