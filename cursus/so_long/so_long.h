/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:21:32 by odemirel          #+#    #+#             */
/*   Updated: 2022/06/03 16:14:47 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MiniLibX/mlx.h"
# include "get_next_line/get_next_line.h"

# define W 13
# define A 0
# define S 1
# define D 2
# define E 14
# define ESC 53

typedef struct window{
	int		x_size;
	int		y_size;
	char	*title;
	void	*p_mlx;
	void	*p_win;
}	t_window;

typedef struct player
{
	int	pos_x;
	int	pos_y;
	int	coin_count;
	int	hp;
}	t_plyr;

typedef struct tiles
{
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
}	t_vars;

#endif