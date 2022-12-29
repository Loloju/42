/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemirel <odemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:46:22 by odemirel          #+#    #+#             */
/*   Updated: 2022/12/29 09:46:23 by odemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_args(argc, argv) == ERROR)
		philo_error("\"CHECK_ARGS(ARGC, ARGV)\" RETURNED_ERROR", ARGS_ERROR);
	start_philo(argc, argv, &data);
	end_philo(&data);
	return (0);
}
