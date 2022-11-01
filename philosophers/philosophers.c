/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:35:06 by odemirel          #+#    #+#             */
/*   Updated: 2022/11/01 15:55:51 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_philosophers
{
	int		p_id;
	int		is_dead;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		must_eat;
}	t_philo;

void	*routine(t_philo psopher)
{
	return (0);
}

t_philo	*philo_init(char **av)
{
	
}

int	main(int ac, char **av)
{
	pthread_t	t1;
	t_philo		*philo1;
	int			must_eat;

	must_eat = 0;
	if(ac == 5 || ac == 6)
	{
		philo1 = philo_init(av);
		pthread_create(&t1, NULL, &routine, &philo1);
		pthread_join(t1, NULL);
		return (1);
	}
}