/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:24:02 by ekaymaz           #+#    #+#             */
/*   Updated: 2022/12/29 10:50:56 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers_bonus.h"

void	print_error_b(char *message)
{
	printf("%s%s\n", CRED, message);
	exit(0);
}

void	act_printer_b(t_philosopher *phil, t_simulation *sim, char *msg)
{
	sem_wait(sim->typing);
	if (!sim->is_dead)
	{
		printf("\033[32m%lli\033[0m:ms \033[1;%dm%d\033[0m %s\n",
			get_time_b() - sim->start_time,
			(phil->id % 7) + 31, phil->id + 1, msg);
	}
	sem_post(sim->typing);
}

long long	get_time_b(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	i_need_sleep_b(t_simulation *sim, long long time)
{
	long long	this_time;

	this_time = get_time_b();
	while (!sim->is_dead)
	{
		if (get_time_b() - this_time >= time)
			break ;
		usleep (42);
	}
}

int	ft_atoi_b(char *ptr)
{
	int	res;
	int	pn;
	int	i;

	i = 0;
	pn = 1;
	res = 0;
	while (ptr[i] == ' ' || (ptr[i] >= 9 && ptr[i] <= 13))
		i++;
	while (ptr[i] == '+' || ptr[i] == '-')
	{
		if (ptr[i] == '-')
			pn *= -1;
		i++;
	}
	while ((ptr[i] >= '0' && ptr[i] <= '9') && ptr[i])
	{
		res = (res * 10) + ptr[i] - 48;
		i++;
	}
	return (res * pn);
}
