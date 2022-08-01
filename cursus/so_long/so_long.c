/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:26:20 by odemirel          #+#    #+#             */
/*   Updated: 2022/08/01 13:58:59 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>

int	exit_game(t_vars *v)
{
	printf("\n");
	mlx_destroy_window(v->win->p_mlx, v->win->p_win);
	free(v->win);
	free(v->plyr);
	free(v->tile);
	free(v->game);
	exit(1);
	return (0);
}

void	draw_map(t_vars *v)
{
	int	y;
	int	x;

	if (v->game->cn == v->plyr->ccnt)
		v->tile->exit = mlx_xpm_file_to_image(v->win->p_mlx, EXT, &v->tile->wdt, &v->tile->hgt);
	y = 0;
	while (y < v->game->m_y_size - 1)
	{
		x = 0;
		while (x < v->game->m_x_size - 1)
		{
			if (v->game->map[y][x] == '0')
				mlx_put_image_to_window(v->win->p_mlx, v->win->p_win, v->tile->gnd, x * IMG, y * IMG);
			else if (v->game->map[y][x] == '1')
				mlx_put_image_to_window(v->win->p_mlx, v->win->p_win, v->tile->wall, x * IMG, y * IMG);
			else if (v->game->map[y][x] == 'P')
			{
				mlx_put_image_to_window(v->win->p_mlx, v->win->p_win, v->tile->gnd, x * IMG, y * IMG);
				mlx_put_image_to_window(v->win->p_mlx, v->win->p_win, v->tile->plyr, x * IMG, y * IMG);
				v->plyr->px = x;
				v->plyr->py = y;
			}
			else if (v->game->map[y][x] == 'C')
			{
				mlx_put_image_to_window(v->win->p_mlx, v->win->p_win, v->tile->gnd, x * IMG, y * IMG);
				mlx_put_image_to_window(v->win->p_mlx, v->win->p_win, v->tile->coin, x * IMG, y * IMG);
			}
			else if (v->game->map[y][x] == 'E')
			{
				mlx_put_image_to_window(v->win->p_mlx, v->win->p_win, v->tile->wall, x * IMG, y * IMG);
				mlx_put_image_to_window(v->win->p_mlx, v->win->p_win, v->tile->exit, x * IMG, y * IMG);
			}
			else
				mlx_put_image_to_window(v->win->p_mlx, v->win->p_win, v->tile->notxt, x * IMG, y * IMG);
			x++;
		}
		y++;
	}
}

int	check_ahead(char *way, int ccnt, int cgoal)
{
	if (*way == '1')
		return (0);
	if (*way == 'C')
		return (2);
	if (*way == '0')
		return (1);
	if (*way == 'E')
	{
		if (ccnt == cgoal)
			return (3);
		return (0);
	}
	return (-1);
}

int	move_player(t_vars *v, char *way)
{
	int	ca;

	ca = check_ahead(way, v->plyr->ccnt, v->game->cn);
	if (ca != 0)
	{
		if (ca == 2)
			v->plyr->ccnt++;
		v->game->map[v->plyr->py][v->plyr->px] = '0';
		*way = 'P';
		v->plyr->mcnt++;
		if (ca == 3)
		{
			draw_map(v);
			exit_game(v);
		}
	}
	return (ca);
}

int	key_control(int keycode, t_vars *v)
{
	if (keycode == ESC)
	{
		//reformat
		exit_game(v);
	}
	else if (keycode == W)
		move_player(v, &v->game->map[v->plyr->py - 1][v->plyr->px]);
	else if (keycode == A)
	{
		move_player(v, &v->game->map[v->plyr->py][v->plyr->px - 1]);
		v->tile->plyr = mlx_xpm_file_to_image(v->win->p_mlx, PLRL,
				&v->tile->wdt, &v->tile->hgt);
	}
	else if (keycode == S)
		move_player(v, &v->game->map[v->plyr->py + 1][v->plyr->px]);
	else if (keycode == D)
	{
		move_player(v, &v->game->map[v->plyr->py][v->plyr->px + 1]);
		v->tile->plyr = mlx_xpm_file_to_image(v->win->p_mlx,
				PLRR, &v->tile->wdt, &v->tile->hgt);
	}
	printf("\rMove Count: %d", v->plyr->mcnt);
	fflush(stdout);
	draw_map(v);
	return (1);
}

/*region*///count_map_size kullanıyor
static int stlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	count_map_size(char *str, t_vars *v)
{
	int		fd;
	int		i;
	int		j;
	char	*a;
	char	*b;

	b = "a";
/* region *///map_size
	fd = open(str, O_RDONLY);
	a = get_line(fd);
	v->game->m_x_size = stlen(a);
	v->game->m_y_size = 1;
	while (*b)
	{
		b = get_line(fd);
		v->game->m_y_size++;
	}
	close(fd);
/*end region*/
	v->game->map = (char **) malloc(sizeof(char *) * (v->game->m_y_size + 1));
/* region */ 
	// assign_map (a null geliyor)
	fd = open(str, O_RDONLY);
	i = 0;
	while (i < v->game->m_y_size)
	{
		a = get_line(fd);
		j = 0;
		while (a[j] != 0)
		{
			if (a[j] == 'C')
				v->game->cn++;
			j++;
		}
		if (stlen(a) == v->game->m_x_size && a != 0)
		{
			v->game->map[i] = a;
			//write(1, v->game->map[i], stlen(v->game->map[i]));
		}
		i++;
	}
	close(fd);
}
/*end region*/

int	main(int ac, char **av)
{
	t_vars		vars;

	if (ac > 1)
	{
		vars.game = (t_game *) malloc(sizeof(t_game));
		vars.game->cn = 0;
		count_map_size(av[1], &vars);
		mlx_instance_init(av, &vars);
		if (vars.win == 0)
			return (-1);
		vars.plyr = player_init();
		vars.tile = tiles_init(vars.win);
		draw_map(&vars);
		mlx_hook(vars.win->p_win, 17, 0, exit_game, &vars);
		//mlx_key_hook(vars.win->p_win, key_control, &vars);
		mlx_hook(vars.win->p_win, KEY_PRESS_EVNT, KEY_PRESS_MSK,
			key_control, &vars);
		mlx_loop(vars.win->p_mlx);
	}
	return (0);
}
