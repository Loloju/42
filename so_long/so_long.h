/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:21:32 by odemirel          #+#    #+#             */
/*   Updated: 2022/08/25 10:23:10 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MiniLibX/mlx.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>

# define KEY_PRESS_EVNT	2
# define IMG			64
# define W				13
# define A				0
# define S				1
# define D				2
# define E				14
# define ESC			53
# define GND			"./tiles/grass.xpm"
# define WLL			"./tiles/wall.xpm"
# define PLRR			"./tiles/plyr.xpm"
# define PLRL			"./tiles/plyrl.xpm"
# define EXT			"./tiles/exit.xpm"
# define EXTC			"./tiles/exitclose.xpm"
# define MSS			"./tiles/missing.xpm"
# define CN				"./tiles/coin.xpm"

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
	int	mcnt;
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
	void	*gnd;
	void	*wall;
	void	*coin;
	void	*exit;
	void	*plyr;
}	t_tiles;

typedef struct vars
{
	t_plyr		*plyr;
	t_tiles		*tile;
	t_window	*win;
	t_game		*game;
}	t_vars;

t_tiles	*tiles_init(t_window *win);
t_plyr	*player_init( void );
t_game	*game_init(void);

char	*get_line(int fd);

int		exit_game(t_vars *v);
int		diag_extension(char *str);

void	mlx_instance_init(char **av, t_vars *v);
void	draw_map(t_vars *v);
void	count_map_size(char *str, t_vars *v);
void	diagnose_map(t_vars *v);
void	ft_error(char *str);
#endif