/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:21:32 by odemirel          #+#    #+#             */
/*   Updated: 2022/06/21 16:14:32 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MiniLibX/mlx.h"
# include "get_next_line/get_next_line.h"

# define IMG 64
# define W 13
# define A 0
# define S 1
# define D 2
# define E 14
# define ESC 53
# define GND "tiles/grass.xpm"
# define WLL "tiles/wall.xpm"
# define PLR "tiles/plyr.xpm"
# define EXT "tiles/exit.xpm"

typedef struct window{
	int		x_size;
	int		y_size;
	char	*title;
	void	*p_mlx;
	void	*p_win;
}	t_window;

typedef struct player
{
	int	px;
	int	py;
	int	ccnt;
	int	mcnt;
	int	hp;
}	t_plyr;

typedef struct game
{
	char	**map;
	int		m_x_size;
	int		m_y_size;
}	t_game;

typedef struct tiles
{
	int		hgt;
	int		wdt;
	void	*bg;
	void	*gnd;
	void	*wall;
	void	*coin;
	void	*exit;
}	t_tiles;

typedef struct vars
{
	t_plyr		*plyr;
	t_tiles		*tile;
	t_window	*win;
	t_game		*game;
}	t_vars;

char	*get_line(int fd, int *flag);
#endif