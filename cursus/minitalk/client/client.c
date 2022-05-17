/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:42:40 by odemirel          #+#    #+#             */
/*   Updated: 2022/05/17 17:29:42 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pid = 0;

void	send_integer(int value)
{
	int	i;

	i = 32;
	while (i > 0)
	{
		if (value >> i & 1)
			kill(g_pid, SIGUSR2);
		else
			kill(g_pid, SIGUSR1);
		usleep(100);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		bit;

	if (ac != 3)
	{
		ft_printf("format: ./client <pid> <message>\n");
		return (-1);
	}
	g_pid = ft_atoi(av[1]);
	send_integer(ft_strlen(av[2]));
	i = -1;
	while (av[2][++i])
	{
		bit = 8;
		while (bit--)
		{
			if (av[2][i] >> bit & 1)
				kill(g_pid, SIGUSR2);
			else
				kill(g_pid, SIGUSR1);
			usleep(100);
		}
	}
	return (0);
}
