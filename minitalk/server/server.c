/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:42:53 by odemirel          #+#    #+#             */
/*   Updated: 2022/05/18 18:13:39 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	action(int signal, siginfo_t *signal_info, void *prevact)
{
	static int				i = 0;
	static pid_t			pid = 0;
	static unsigned char	c;

	( void ) prevact;
	pid = signal_info->si_pid;
	c |= (signal == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(pid, SIGUSR1);
			printf("\n");
			pid = 0;
			return ;
		}
		ft_printf("%c", c);
		kill(pid, SIGUSR2);
		usleep(100);
		c = 0;
	}
	else
		c <<= 1;
}

int	main( void )
{
	struct sigaction	s_sigaction;

	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
