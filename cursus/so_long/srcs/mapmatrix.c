/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmatrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:13:38 by odemirel          #+#    #+#             */
/*   Updated: 2022/08/22 11:08:22 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	set_map_size(t_vars *v)
{
	char	**map;

	map = v->game->map;
	v->game->m_x_size = ft_strlen(map[v->game->m_y_size]);
	while (map[v->game->m_y_size])
		v->game->m_y_size++;
}

void	count_map_size(char *str, t_vars *v)
{
	int		fd;
	int		readed;
	char	*a;
	char	*f;

	f = malloc(sizeof(char) * 0);
	*f = 0;
	a = malloc(sizeof(char) * 2);
	a[1] = 0;
	fd = open(str, O_RDONLY);
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
	set_map_size(v);
}
/*
void	count_map_size(char *str, t_vars *v)
{
	int		fd;
	char	*a;
	char	*f;

	fd = open(str, O_RDONLY);
	a = malloc(sizeof(char));
	f = malloc(sizeof(char));
	while (a)
	{
		a = get_next_line(fd);
		ft_printf("%p\n", a);
		if (a != 0)
			f = ft_strjoin(f, a);
		free(a);
	}
	close(fd);
	free(a);

	v->game->map = ft_split(f, '\n');
	free(f);
	set_map_size(v);
}
*/
