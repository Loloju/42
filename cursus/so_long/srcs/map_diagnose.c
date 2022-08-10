/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_diagnose.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:07:12 by odemirel          #+#    #+#             */
/*   Updated: 2022/08/10 12:58:32 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	set_flag(int flag, char element)
{
	if (flag == 1)
	{
		if (element != 'C')
		{
			ft_printf("Haritada birden fazla %c var!", element);
			return (0);
		}
	}
	return (1);
}

static int	diag_extension(char *str)
{
	int	size;

	size = ft_strlen(str);
	while (str[size] != '.')
		size--;
	if (ft_strnstr(&str[size + 1], "ber\0", 4))
		return (1);
	else
	{	
		ft_printf("uzantı uyumsuz.");
		return (0);
	}
}

static int	diagnose(t_vars *v, char element)
{
	int		x;
	int		y;
	int		flag;
	char	**map;

	flag = 0;
	map = v->game->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == element)
			{
				flag = set_flag(flag, element);
				if (flag == 0)
					return (0);
			}
			x++;
		}
		y++;
	}
	return (flag);
}

void	diagnose_map(t_vars *v, char *str)
{
	int	pass;

	pass = 1;
	pass *= diagnose(v, 'C');
	pass *= diagnose(v, 'P');
	pass *= diagnose(v, 'E');
	pass *= diag_extension(str);
	if (pass == 0)
		exit_game(v);
}
