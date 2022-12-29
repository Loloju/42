/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:46:10 by odemirel          #+#    #+#             */
/*   Updated: 2022/12/29 09:46:11 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_philo(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&data->write);
	while (++i < data->n_philos)
		pthread_mutex_destroy(&data->fork[i]);
	free(data->fork);
	free(data->philo);
}
