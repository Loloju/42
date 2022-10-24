/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:42:40 by odemirel          #+#    #+#             */
/*   Updated: 2022/08/05 09:48:56 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_loop = 1;

static void	setflag(int signal)
{
	static int	count = 0;

	if (signal == SIGUSR2)
	{
		count++;
		ft_printf("\nRecieved");
	}
	else
	{
		g_loop = 0;
		ft_printf("\nSent %d!\n", count);
	}
}

static void	send_signal(int pid, char *str)
{
	int	i;
	int	bit;

	i = -1;
	while (str[++i])
	{
		bit = 8;
		while (bit--)
		{
			if ((str[i] >> bit) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(1000);
		}
	}
	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR1);
		usleep(1000);
	}
}

int	main(int ac, char **av)
{
	int		pid;

	if (ac != 3)
	{
		ft_printf("format: ./oclient <pid> <message>\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, setflag);
	signal(SIGUSR2, setflag);
	send_signal(pid, av[2]);
	while (g_loop)
	{
		pause();
	}
	return (0);
}
