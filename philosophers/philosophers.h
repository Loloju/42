/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:12:52 by odemirel          #+#    #+#             */
/*   Updated: 2022/12/13 13:13:58 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define STR_SLEEP "is \033[1;34;4msleeping\033[0m"
# define STR_EAT "is \033[1;32meating\033[0m"
# define STR_THINK "is \033[1;33mthinking\033[0m"
# define STR_FORK_LEFT "has taken left fork."
# define STR_FORK_RIGHT "has taken right fork."
# define STR_DIE "\033[1;2;31;9mdied!\033[0m"

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
	int			philo_id;
	int			p_eat_count;
	int			left_fork;
	int			right_fork;
	long		last_meal;
	long		time;
	pthread_t	thread;

	t_data		*ph_data;
}	t_philo;

int	ft_atoi(const char *nptr);

#endif