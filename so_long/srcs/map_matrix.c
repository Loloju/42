/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:13:38 by odemirel          #+#    #+#             */
/*   Updated: 2022/08/25 10:32:42 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	integrity_check(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map[y])
	{
		if (y == 0 || y == (g->m_y_size - 1))
		{
			x = 0;
			while (g->map[y][x] != '\0')
			{
				if (g->map[y][x] != '1')
					return (0);
				x++;
			}
		}
		if (g->map[y][0] != '1' || g->map[y][g->m_x_size - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

static void	no_file( void )
{
	ft_error("Dosya bulunamadı!\n");
	exit(1);
}

static int	issquare(t_game *g)
{
	int	i;

	i = 0;
	while (g->map[i])
	{
		if ((int) ft_strlen(g->map[i]) != g->m_x_size)
			return (0);
		i++;
	}
	return (1);
}

static void	set_map_size(t_game *g)
{
	g->m_x_size = ft_strlen(g->map[g->m_y_size]);
	while (g->map[g->m_y_size])
		g->m_y_size++;
	if (!issquare(g))
	{
		ft_error("Harita Dikdörtgen değil!");
		exit(1);
	}
	if (!integrity_check(g))
	{
		ft_error("Harita duvarlarında delik(ler) var!");
		exit(1);
	}
}

void	count_map_size(char *str, t_vars *v)
{
	int		fd;
	int		readed;
	char	*a;
	char	*f;

	f = malloc(sizeof(char) * 1);
	*f = 0;
	a = malloc(sizeof(char) * 2);
	a[1] = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		no_file();
	readed = -2;
	while (readed > 0 || readed == -2)
	{
		readed = read(fd, a, 1);
		f = ft_strjoin(f, a);
	}
	free(a);
	v->game->map = ft_split(f, '\n');
	free(f);
	close(fd);
	set_map_size(v->game);
}
