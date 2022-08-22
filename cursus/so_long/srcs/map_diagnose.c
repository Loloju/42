/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_diagnose.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:07:12 by odemirel          #+#    #+#             */
/*   Updated: 2022/08/22 10:35:28 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(char *str)
{
	ft_printf("Error:\n\t%s", str);
}

static int	set_flag(t_vars *v, int flag, char element)
{
	if (element == 'C')
		v->game->cn++;
	if (flag == 1)
	{
		if (element != 'C')
		{
			ft_error("");
			ft_printf("Haritada birden fazla %c var!", element);
			exit_game(v);
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
	if (str[size + 1] == 'b' && str[size + 2] == 'e'
		&& str[size + 3] == 'r' && str[size + 4] == '\0')
		return (1);
	else
	{	
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
	while (map[y] != 0)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == element)
			{
				flag = set_flag(v, flag, element);
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
	if (!diagnose(v, 'C'))
	{
		ft_error("Haritada coin yok.\n");
		exit_game(v);
	}
	if (!diagnose(v, 'P'))
	{
		ft_error("Haritada player yok.\n");
		exit_game(v);
	}
	if (!diagnose(v, 'E'))
	{
		ft_error("Haritada çıkış yok.\n");
		exit_game(v);
	}
	if (!diag_extension(str))
	{
		ft_error("Uzantı uyumsuz!");
		exit_game(v);
	}
}
