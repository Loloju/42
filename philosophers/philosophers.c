/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:35:06 by odemirel          #+#    #+#             */
/*   Updated: 2022/12/09 16:11:56 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_to_screen(int time, t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->ph_data->print_lock);
	printf("\033[%dm%dms %d %s\n", (philo->philo_id % 8) + 30,
		time, philo->philo_id, str);
	fflush(stdout);
	pthread_mutex_unlock(&philo->ph_data->print_lock);
}

long	get_time( void )
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	philo_eat( void )
{
	
}

void	*routine(void *param)
{
	int		time_passed;
	t_philo	*p;

	p = (t_philo *) param;
	if (p->philo_id % 2 == 0)
		usleep(p->ph_data->time_sleep * 1000);
	while (1)
	{
		time_passed = get_time() - p->start_time;
		print_to_screen(time_passed / 2, p, STR_THINK);
	}
	return (0);
}

t_data	*initialization(int ac, char **av)
{
	static int	sint = 0;
	t_data		*data;
	int			i;

	i = 0;
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
	data->fork_lock = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	i = 0;
	pthread_mutex_init(&data->print_lock, NULL);
	return (data);
}

void	init_philo(int index, t_data *envvar, t_philo *philo)
{
	philo->philo_id = index + 1;
	philo->last_meal = 0;
	philo->left_fork = index;
	philo->right_fork = ((index + 1) % envvar->philo_num);
	philo->start_time = get_time();
	philo->thread = malloc(sizeof(pthread_t));
	philo->ph_data = envvar;
}

int	main(int ac, char **av)
{
	int			i;
	t_data		*envvar;
	t_philo		*philos;

	i = 0;
	if (ac == 5 || ac == 6)
	{
		envvar = initialization(ac, av);
		philos = (t_philo *)malloc(sizeof(t_philo) * envvar->philo_num);
		while (i < envvar->philo_num)
		{
			init_philo(i, envvar, &philos[i]);
			i++;
		}
		i = 0;
		while (i < envvar->philo_num)
		{
			pthread_create(&philos->thread, NULL, &routine, &philos[i]);
			i++;
		}
		i = 0;
		while (i < envvar->philo_num)
		{
			pthread_join((&philos[i])->thread, NULL);
			i++;
		}
	}
	else
	{
		printf("Argüman sayısı yanlış.\n");
		return (1);
	}
	return (0);
}
