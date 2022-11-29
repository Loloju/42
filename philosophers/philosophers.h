/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:12:52 by odemirel          #+#    #+#             */
/*   Updated: 2022/11/29 12:01:00 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int				philo_num;
	int				has_died;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	int				total_meal;

	pthread_mutex_t	print_lock;
	pthread_mutex_t	*fork_lock;
}	t_data;

typedef struct s_philo
{
	int		philo_id;
	int		p_eat_count;
	int		left_fork;
	int		right_fork;
	long	last_meal;
	long	start_time;

	t_data	*philo_data;
}	t_philo;

int	ft_atoi(const char *nptr);

#endif