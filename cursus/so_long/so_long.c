/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:26:20 by odemirel          #+#    #+#             */
/*   Updated: 2022/06/21 16:05:32 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	check_ahead(char *way)
{
	if (*way == '1')
		return (0);
	if (*way == 'C')
		return (2);
	if (*way == '0')
		return (1);
	return (-1);
}

void	move_player(t_vars *v, char *way)
{
	int	ca;

	ca = check_ahead(way);
	if (ca != 0)
	{
		if (ca == 2)
			v->plyr->ccnt++;
		v->game->map[v->plyr->py][v->plyr->px] = '0';
		*way = 'P';
	}
}

int	key_control(int keycode, t_vars *v)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(v->win->p_mlx, v->win->p_win);
		exit(1);
	}
	/* else if (keycode == W)
	{
		move_player(v, &v->game->map[v->plyr->py - 1][v->plyr->px]);
		v->plyr->mcnt++;
	}
	else if (keycode == A)
	{
		move_player(v, &v->game->map[v->plyr->py][v->plyr->px - 1]);
		v->plyr->mcnt++;
	}
	else if (keycode == S)
	{
		move_player(v, &v->game->map[v->plyr->py + 1][v->plyr->px]);
		v->plyr->mcnt++;
	}
	else if (keycode == D)
	{
		move_player(v, &v->game->map[v->plyr->py][v->plyr->px + 1]);
		v->plyr->mcnt++;
	} */
	return (1);
}

t_window	*mlx_instance_init(char **av, t_vars *v)
{
	t_window	*win;

	win = (t_window *) malloc(sizeof(t_window));
	win->x_size = v->game->m_x_size * IMG;
	win->y_size = v->game->m_y_size * IMG;
	printf("%d x %d", win->x_size, win->y_size);
	win->title = av[1];
	win->p_mlx = mlx_init();
	if (win->p_mlx != 0)
	{
		win->p_win = mlx_new_window(win->p_mlx, win->x_size,
				win->y_size, win->title);
	}
	else
	{
		return (0);
	}
	return (win);
}

t_tiles	*tiles_init(t_window *win)
{
	t_tiles	*t;

	t = (t_tiles *) malloc(sizeof(t_tiles));
	t->gnd = mlx_xpm_file_to_image(win->p_mlx, GND, &t->wdt, &t->hgt);
	t->wall = mlx_xpm_file_to_image(win->p_mlx, WLL, &t->wdt, &t->hgt);
	t->exit = mlx_xpm_file_to_image(win->p_mlx, EXT, &t->wdt, &t->hgt);
	return (t);
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
	// int		i;
	char	*a;
	char	*b = "a";

/* region *///map_size
	printf("map_size");
	fflush(stdout);
	fd = open(str, O_RDONLY);
	a = get_line(fd);
	v->game->m_x_size = stlen(a);
	v->game->m_y_size = 1;
	while (b)
	{
		b = get_line(fd);
		v->game->m_y_size++;
	}
	close(fd);
/*end region*/
	v->game->map = (char **) malloc(sizeof(char *) * v->game->m_y_size);
/* region */ 
	// assign_map (a null geliyor)
	/* printf("map_assign");
	fd = open(str, O_RDONLY);
	i = 0;
	while (i <= v->game->m_y_size)
	{
		a = get_line(fd);
		if (stlen(a) == v->game->m_x_size)
		{
			v->game->map[i] = a;
			write(1, v->game->map[i], stlen(v->game->map[i]));
			write(1,"a",1);
			i++;
		}
		else
		{
			printf("map error x size differ..");
			exit(1);
		}
		i++;
	}
	close(fd); */
}
/*end region*/

t_plyr *player_init( void )
{
	t_plyr	*plyr;

	plyr = (t_plyr *) malloc(sizeof(t_plyr));
	plyr->ccnt = 0;
	plyr->mcnt = 0;
	plyr->hp = 0;
	plyr->px = 0;
	plyr->py = 0;
	return (plyr);
}

int	main(int ac, char **av)
{
	t_vars		vars;

	if (ac > 1)
	{
		printf("%s\n", av[1]);
		vars.game = (t_game *) malloc(sizeof(t_game));
		count_map_size(av[1], &vars);
		vars.win = mlx_instance_init(av, &vars);
		if (vars.win == 0)
			return (-1);
		vars.plyr = player_init();
		vars.tile = tiles_init(vars.win);
		vars.plyr->mcnt += mlx_key_hook(vars.win->p_win, key_control, &vars);
		//mlx_loop(vars.win->p_mlx);
		free(vars.win);
		free(vars.plyr);
		free(vars.tile);
		free(vars.game);
	}
	return (0);
}
