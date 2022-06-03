/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:26:20 by odemirel          #+#    #+#             */
/*   Updated: 2022/06/03 16:16:55 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_control(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->win->p_mlx, vars->win->p_win);
	}
	else if (keycode == W)
	{
		move_up();
	}
	else if (keycode == A)
	{
		move_left();
	}
	else if (keycode == S)
	{
		move_down();
	}
	else if (keycode == D)
	{
		move_right();
	}
}

int	main(int ac, char **av)
{
	int			counter;
	int			fd;
	char		**map;
	t_window	*win;
	t_vars		vars;

	if (ac > 1)
	{
		counter = 0;
		count_map_size(av[1]);
		win = (t_window *) malloc(sizeof(t_window));
		win->x_size = 1024;
		win->y_size = 768;
		win->title = av[1];
		win->p_mlx = mlx_init();
		win->p_win = mlx_new_window(win->p_mlx, win->x_size,
				win->y_size, win->title);
		mlx_key_hook(win->p_win, key_control, &vars);
		mlx_loop(win->p_mlx);
		free(win);
		free(map); //external free
	}
	return (0);
}
