/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:42:53 by odemirel          #+#    #+#             */
/*   Updated: 2022/05/09 14:38:02 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	action(int signal, siginfo_t *client_pid, void *prevact)
{
	static int				i = 0;
	static pid_t			pid = 0;
	static unsigned char	c;

	pid = client_pid->si_pid;
	c |= (signal == SIGUSR2);
	if (i++ == 8)
	{
		i = 0;
		if (!c)
		{
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
	struct sigaction	s_sigaction;

	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	return (0);
}
