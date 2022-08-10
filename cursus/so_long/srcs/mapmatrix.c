/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmatrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:13:38 by odemirel          #+#    #+#             */
/*   Updated: 2022/08/10 12:26:47 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	put_matrix(char *str, t_vars *v)
{
	int		fd;
	int		i;
	int		j;
	char	*a;

	fd = open(str, O_RDONLY);
	i = 0;
	while (i < v->game->m_y_size)
	{
		a = get_line(fd);
		j = 0;
		while (a[j] != 0)
		{
			if (a[j] == 'C')
				v->game->cn++;
			j++;
		}
		if ((int) ft_strlen(a) == v->game->m_x_size && a != 0)
		{
			v->game->map[i] = a;
		}
		i++;
	}
	close(fd);
}

void	count_map_size(char *str, t_vars *v)
{
	int		fd;
	char	*a;

	fd = open(str, O_RDONLY);
	a = get_line(fd);
	v->game->m_x_size = (int) ft_strlen(a);
	v->game->m_y_size = 1;
	while (*a)
	{
		free(a);
		a = get_line(fd);
		v->game->m_y_size++;
	}
	free(a);
	close(fd);
	v->game->map = (char **) malloc(sizeof(char *) * (v->game->m_y_size + 1));
	v->game->map[v->game->m_y_size] = 0;
	put_matrix(str, v);
}
