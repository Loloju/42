/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_diagnose.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:07:12 by odemirel          #+#    #+#             */
/*   Updated: 2022/08/25 12:22:38 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(char *str)
{
	ft_printf("Hata:\n\t%s", str);
}

static int	set_flag(t_vars *v, int flag, char element)
{
	if (element == 'C')
		v->game->cn++;
	if (flag == 1)
	{
		if (element == 'P')
		{
			ft_error("");
			ft_printf("Haritada birden fazla %c var!", element);
			exit_game(v);
		}
	}
	return (1);
}

int	diag_extension(char *str)
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

void	diagnose_map(t_vars *v)
{
	int	f;

	f = 0;
	if (!diagnose(v, 'C'))
	{
		ft_error("Haritada coin yok.\n");
		f = 1;
	}
	if (!diagnose(v, 'P'))
	{
		ft_error("Haritada player yok.\n");
		f = 1;
	}
	if (!diagnose(v, 'E'))
	{
		ft_error("Haritada çıkış yok.\n");
		f = 1;
	}
	if (f)
		exit_game(v);
}
