/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:21:32 by odemirel          #+#    #+#             */
/*   Updated: 2022/07/04 13:39:52 by odemirel         ###   ########.fr       */
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
# define PLRR "tiles/plyr.xpm"
# define PLRL "tiles/plyrl.xpm"
# define EXT "tiles/exit.xpm"
# define EXTC "tiles/exitclose.xpm"
# define MSS "tiles/missing.xpm"
# define CN "tiles/coin.xpm"

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
	int		cn;
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
	void	*notxt;
	void	*plyr;
}	t_tiles;

typedef struct vars
{
	t_plyr		*plyr;
	t_tiles		*tile;
	t_window	*win;
	t_game		*game;
}	t_vars;

char	*get_line(int fd);
#endif