/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:38:31 by odemirel          #+#    #+#             */
/*   Updated: 2022/08/17 16:57:15 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_ce(t_vars *v, int y, int x)
{
	if (v->game->map[y][x] == 'C')
	{
		mlx_put_image_to_window(v->win->p_mlx, v->win->p_win,
			v->tile->gnd, x * IMG, y * IMG);
		mlx_put_image_to_window(v->win->p_mlx, v->win->p_win,
			v->tile->coin, x * IMG, y * IMG);
	}
	else if (v->game->map[y][x] == 'E')
	{
		mlx_put_image_to_window(v->win->p_mlx, v->win->p_win,
			v->tile->wall, x * IMG, y * IMG);
		mlx_put_image_to_window(v->win->p_mlx, v->win->p_win,
			v->tile->exit, x * IMG, y * IMG);
	}
	else
	{
		ft_error("");
		ft_printf("Haritada tanımlanmamış değer (\"%c\") var! x : %d , y : %d\n",
			v->game->map[y][x], x, y);
		exit_game(v);
	}
}

static void	check_01p(t_vars *v, int y, int x)
{
	if (v->game->map[y][x] == '0')
		mlx_put_image_to_window(v->win->p_mlx,
			v->win->p_win, v->tile->gnd, x * IMG, y * IMG);
	else if (v->game->map[y][x] == '1')
		mlx_put_image_to_window(v->win->p_mlx,
			v->win->p_win, v->tile->wall, x * IMG, y * IMG);
	else if (v->game->map[y][x] == 'P')
	{
		mlx_put_image_to_window(v->win->p_mlx, v->win->p_win,
			v->tile->gnd, x * IMG, y * IMG);
		mlx_put_image_to_window(v->win->p_mlx, v->win->p_win,
			v->tile->plyr, x * IMG, y * IMG);
		v->plyr->px = x;
		v->plyr->py = y;
	}
	else
		check_ce(v, y, x);
}

void	draw_map(t_vars *v)
{
	int	y;
	int	x;

	if (v->game->cn == 0)
		v->tile->exit = mlx_xpm_file_to_image(v->win->p_mlx, EXT,
				&v->tile->wdt, &v->tile->hgt);
	y = 0;
	while (y < v->game->m_y_size)
	{
		x = 0;
		while (x < v->game->m_x_size)
		{
			check_01p(v, y, x);
			x++;
		}
		y++;
	}
}
