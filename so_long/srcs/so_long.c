/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:26:20 by odemirel          #+#    #+#             */
/*   Updated: 2022/08/25 10:22:46 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_game(t_vars *v)
{
	int	i;

	i = 0;
	ft_printf("\n");
	mlx_destroy_window(v->win->p_mlx, v->win->p_win);
	free(v->win);
	free(v->plyr);
	free(v->tile);
	while (v->game->map[i] != 0)
	{
		free(v->game->map[i]);
		i++;
	}
	free(v->game->map);
	free(v->game);
	exit(1);
	return (0);
}

int	check_ahead(char *way, int cgoal)
{
	if (*way == '1')
		return (0);
	if (*way == 'C')
		return (2);
	if (*way == '0')
		return (1);
	if (*way == 'E')
	{
		if (cgoal == 0)
			return (3);
		return (0);
	}
	return (-1);
}

int	move_player(t_vars *v, char *way)
{
	int	ca;

	ca = check_ahead(way, v->game->cn);
	if (ca != 0)
	{
		if (ca == 2)
			v->game->cn--;
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
	ft_printf("\rMove Count: \033[33;1;3m%d\033[0m", v->plyr->mcnt);
	draw_map(v);
	return (1);
}

int	main(int ac, char **av)
{
	t_vars		vars;

	if (ac == 2)
	{
		if (!diag_extension(av[1]))
		{
			ft_error("Uzantı uyumsuz!");
			exit(1);
		}
		vars.game = game_init();
		count_map_size(av[1], &vars);
		mlx_instance_init(av, &vars);
		if (vars.win == 0)
			return (-1);
		vars.plyr = player_init();
		vars.tile = tiles_init(vars.win);
		draw_map(&vars);
		diagnose_map(&vars);
		mlx_hook(vars.win->p_win, 17, 0, exit_game, &vars);
		mlx_hook(vars.win->p_win, KEY_PRESS_EVNT, (1L << 0),
			key_control, &vars);
		mlx_loop(vars.win->p_mlx);
	}
	return (0);
}
