# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 10:16:38 by odemirel          #+#    #+#              #
#    Updated: 2022/07/27 09:29:30 by odemirel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
MLX = MiniLibX/
LIB = libft/
FLAGS = -Wall -Werror -Wextra
OPENGLFLAGS = -framework OpenGL -framework AppKit -L./minilibx -lmlx

all: $(NAME)

$(NAME):
	@make -C $(LIB)
	@gcc $(FLAGS) $(OPENGLFLAGS) so_long.c init.c get_line.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strchr.c so_long.h -g
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