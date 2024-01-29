/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:50:00 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/01/29 15:57:21 by ohosnedl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_loop(t_philos *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == true)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	*philo_routine(void *pointer)
{
	t_philos	*philo;

	philo = (t_philos *)pointer;
	return (NULL);
}

void	*monitor(void	*pointer)
{
	t_philos	*philos;

	philos = (t_philos *)pointer;
	while (1)
	{
		if (check_dead(philos) == 1 || check_full(philos) == 1)
			break ;
	}
	return (NULL);
}

void	create_threads(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	checker;
	int			i;

	i = -1;
	if (pthread_create(&checker, NULL, &monitor, program->philos) != 0)
		destroy_all("Thread creation error", program, forks);
	while (++i < program->philos[0].num_of_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL,
				&philo_routine, &program->philos[i]) != 0)
			destroy_all("Thread creation error", program, forks);
	}
	i = -1;
	if (pthread_join(checker, NULL) != 0)
		destroy_all("Thread join error", program, forks);
	while (++i < program->philos[0].num_of_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			destroy_all("Thread join error", program, forks);
	}
}
