/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:15:56 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/02/01 16:48:48 by ohosnedl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	while (!get_bool(&philo->data->data_lock, philo->dead))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

static void	*monitor(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
}

void	create_threads(t_data *data)
{
	pthread_t	checker;
	int			i;

	i = -1;
	safe_thread(&checker, &monitor, data->philo, CREATE);
	while (++i < data->num_of_philos)
		safe_thread(&data->philo[i].thread, &philo_routine, &data->philo[i], CREATE);
	i = -1;
	safe_thread(&checker, NULL, NULL, JOIN);
	while (++i < data->num_of_philos)
		safe_thread(&data->philo[i].thread, NULL, NULL, JOIN);
}
