/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:35:06 by odemirel          #+#    #+#             */
/*   Updated: 2022/11/29 15:11:18 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *param)
{
	t_philo	*psopher;

	psopher = (t_philo *) param;
	return (0);
}

t_data	*initialization(int ac, char **av)
{
	static int	sint = 0;
	t_data		*data;

	data = malloc(sizeof(t_data));
	if (ft_atoi(av[1]) <= 1)
		data->has_died = 1;
	sint++;
	data->philo_num = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = 0;
	return (data);
}

t_philo	*init_philo(t_data data)
{
	static int	sint = 0;
	t_philo		*data;

	data = malloc(sizeof(t_philo));
	if (ft_atoi(av[1]) <= 1)
		data->has_died = 1;
	sint++;
	data->philo_num = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = 0;
	return (data);
}

int	main(int ac, char **av)
{
	int			pnumber;
	pthread_t	*threads;
	t_data		*envvar;
	t_philo		*philos;
	time_t		t;

	pnumber = 0;
	threads = malloc(sizeof(pthread_t) * pnumber);
	if (ac == 5 || ac == 6)
	{
		envvar = initialization(ac, av);
		printf("Number: %d\nTime to die: %d\nTime to eat: %d\nTime to sleep: %d\nMinimum Meals: %d\n",
			envvar->philo_num, envvar->time_die,
			envvar->time_eat, envvar->time_sleep, envvar->must_eat);
		philos = init_philo();
		pthread_create(threads, NULL, &routine, philos);
		pthread_join(*threads, NULL);
	}
	else
	{
		printf("Argüman sayısı yanlış.\n");
		return (1);
	}
	return (0);
}
