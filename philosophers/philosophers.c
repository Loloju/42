/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:35:06 by odemirel          #+#    #+#             */
/*   Updated: 2022/12/13 16:26:31 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	msleep(int duration)
{
	usleep(duration * 1000);
}

void	print_to_screen(int time, t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->ph_data->print_lock);
	if (!philo->ph_data->has_died)
	{
		printf("%dms \033[1;%dm%d\033[0m %s\n", time, (30 + (philo->philo_id % 5)),
			philo->philo_id, str);
	}
	fflush(stdout);
	pthread_mutex_unlock(&philo->ph_data->print_lock);
}

long	get_time( void )
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	philo_eat(t_philo *p)
{
	int	time;

	time = get_time();
	pthread_mutex_lock(&p->ph_data->fork_lock[p->left_fork]);
	print_to_screen(time - p->time, p, STR_FORK_LEFT);
	pthread_mutex_lock(&p->ph_data->fork_lock[p->right_fork]);
	print_to_screen(time - p->time, p, STR_FORK_RIGHT);
	print_to_screen(time - p->time, p, STR_EAT);
	msleep(p->ph_data->time_eat);
	pthread_mutex_unlock(&p->ph_data->fork_lock[p->left_fork]);
	pthread_mutex_unlock(&p->ph_data->fork_lock[p->right_fork]);
}

int	is_dead(t_philo *p)
{
	if (get_time() - p->last_meal > p->ph_data->time_die)
		return (1);
	return (0);
}

void	philo_die(t_philo *p)
{
	p->ph_data->has_died = 1;
	print_to_screen(get_time() - p->time, p, STR_DIE);
}

void	*routine(void *param)
{
	int		time_passed;
	t_philo	*p;

	p = (t_philo *) param;
	if (p->philo_id % 2 == 0)
		msleep(p->ph_data->time_sleep);
	while (p->ph_data->has_died != 1)
	{
		philo_eat(p);
		print_to_screen(time_passed, p, STR_SLEEP);
		msleep(p->ph_data->time_sleep);
		time_passed = get_time() - p->time;
		print_to_screen(time_passed, p, STR_THINK);
		/* if (get_time() - p->last_meal > p->ph_data->time_eat)
			philo_die(p); */ // * (yapıldı.) Main'de sonsuz döngüye taşı!
	}
	return (0);
}

t_data	*initialization(int ac, char **av)
{
	t_data		*data;
	int			i;

	i = 0;
	data = malloc(sizeof(t_data));
	data->has_died = 0;
	if (ft_atoi(av[1]) <= 1)
		data->has_died = 1;
	data->philo_num = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = 0;
	data->fork_lock = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	pthread_mutex_init(&data->print_lock, NULL);
	return (data);
}

void	init_philo(int index, t_data *envvar, t_philo *philo)
{
	philo->philo_id = index + 1;
	philo->time = get_time();
	philo->last_meal = philo->time;
	philo->left_fork = index;
	philo->right_fork = ((index + 1) % envvar->philo_num);
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
		printf("yo\n");
		while (1)
		{
			i = 0;
			while (&philos[i]) // ? segfault?
			{
				if (is_dead(&philos[i]))
				{
					philo_die(&philos[i]); // ? segfault?
					break ;
				}
				i++;
			}
			if (is_dead(&philos[i]))
				break ;
		}
		printf("hi\n");
		// * (Yapıldı.) Dead Check buraya gelecek (while)
		i = 0;
		while (i < envvar->philo_num)
		{
			pthread_join((&philos[i])->thread, NULL);
			i++;
		}
		printf("bye\n");
		return (0);
	}
	else
	{
		printf("Argüman sayısı yanlış.\n");
		return (1);
	}
	return (0);
}
