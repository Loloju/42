/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:35:48 by odemirel          #+#    #+#             */
/*   Updated: 2022/12/29 10:09:44 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define ERROR -1

# define ARGS_ERROR -2
# define MALLOC_ERROR -3

# define STR_THINKING	"is \033[1;33mthinking\033[0m"
# define STR_EATING		"is \033[1;32meating\033[0m"
# define STR_SLEEPING	"is \033[1;34;4msleeping\033[0m"
# define STR_TOOK_FORK	"has taken a \033[1;35mfork\033[0m"
# define STR_DEAD		"\033[1;2;31;9mdied!\033[0m"

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int					id;
	int					l_fork;
	int					r_fork;
	int					eat_count;
	bool				finished;
	unsigned long int	last_eat;
	pthread_t			thread_id;
	t_data				*data;
}	t_philo;

typedef struct s_data
{
	int					n_philos;
	int					tt_die;
	int					tt_eat;
	int					tt_sleep;
	int					should_eat;
	int					action;
	bool				running;
	unsigned long int	start;
	pthread_mutex_t		*fork;
	pthread_mutex_t		write;
	t_philo				*philo;
}	t_data;

//philo.c
void				*philo_main_loop(void *args);
void				*philo_observe(void *args);

//action.c
void				pthink(t_philo *philo);
void				peat(t_philo *philo);
void				psleep(t_philo *philo);
void				ptake_forks(t_philo *philo);
void				pdrop_forks(t_philo *philo);

//init.c
void				start_philo(int argc, char **argv, t_data *data);

//args.c
int					check_args(int argc, char **argv);
void				set_up_args(int argc, char **argv, t_data *data);

//error.c
void				philo_error(char *error, int error_id);
void				malloc_error_info(char *error);
void				args_error_info(char *error);

//free.c
void				end_philo(t_data *data);

//utils.c
int					ft_atoi(char *nbr);
void				print_action(char *action, t_philo *philo,
						unsigned long int ms);
unsigned long int	get_ms(void);

#endif