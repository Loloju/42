/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 09:30:34 by odemirel          #+#    #+#             */
/*   Updated: 2022/08/17 17:04:54 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mlx_instance_init(char **av, t_vars *v)
{
	t_window	*win;

	win = (t_window *) malloc(sizeof(t_window));
	win->x_size = (v->game->m_x_size) * IMG;
	win->y_size = (v->game->m_y_size) * IMG;
	win->title = av[1];
	win->p_mlx = mlx_init();
	if (win->p_mlx != 0)
	{
		win->p_win = mlx_new_window(win->p_mlx, win->x_size,
				win->y_size, win->title);
	}
	else
	{
		return ;
	}
	v->win = win;
}

t_tiles	*tiles_init(t_window *win)
{
	t_tiles	*t;

	t = (t_tiles *) malloc(sizeof(t_tiles));
	t->gnd = mlx_xpm_file_to_image(win->p_mlx, GND, &t->wdt, &t->hgt);
	t->wall = mlx_xpm_file_to_image(win->p_mlx, WLL, &t->wdt, &t->hgt);
	t->exit = mlx_xpm_file_to_image(win->p_mlx, EXTC, &t->wdt, &t->hgt);
	t->plyr = mlx_xpm_file_to_image(win->p_mlx, PLRR, &t->wdt, &t->hgt);
	t->coin = mlx_xpm_file_to_image(win->p_mlx, CN, &t->wdt, &t->hgt);
	return (t);
}

t_plyr	*player_init( void )
{
	t_plyr	*plyr;

	plyr = (t_plyr *) malloc(sizeof(t_plyr));
	plyr->mcnt = 0;
	plyr->px = 0;
	plyr->py = 0;
	return (plyr);
}

t_game	*game_init( void )
{
	t_game	*game;

	game = (t_game *) malloc(sizeof(t_game));
	game->cn = 0;
	game->m_x_size = 0;
	game->m_x_size = 0;
	game->map = NULL;
	return (game);
}
