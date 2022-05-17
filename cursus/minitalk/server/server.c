/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:42:53 by odemirel          #+#    #+#             */
/*   Updated: 2022/05/17 17:57:45 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	action(int signal, siginfo_t *client_pid, void *prevact)
{
	static int				i = 0;
	static pid_t			pid = 0;
	static unsigned char	c;
	static int				flag = 0;

	( void ) prevact;
	pid = client_pid->si_pid;
	c |= (signal == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			//kill(client_pid, SIGUSR1);
			pid = 0;
			return ;
		}
		ft_printf("%c", c);
		c = 0;
	}
	else
		c <<= 1;
}

int	main( void )
{
	int					i;
	struct sigaction	s_sigaction;

	i = 0;
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
