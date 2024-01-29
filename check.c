/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:13:05 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/01/29 15:57:01 by ohosnedl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_dead(t_philos *philo, int time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (gettime() - philo->last_meal_time >= time_to_die
		&& philo->eating == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	check_dead(t_philos *philos)
{
	int	i;

	i = -1;
	while (++i < philos[0].num_of_philos)
	{
		if (philo_dead(&philos[i], philos[i].time_to_die))
		{
			print_msg("died", &philos[i], philos[i].id);
			pthread_mutex_lock(philos[0].dead_lock);
			*philos->dead = true;
			pthread_mutex_unlock(philos[0].dead_lock);
			return(1);
		}
	}
	return (0);
}

int	check_full(t_philos *philos)
{
	int i;
	int	full;

	i = -1;
	full = 0;
	if (philos->meals_num == -1)
		return (0);
	while (++i < philos->num_of_philos)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten == philos[i].meals_num)
			full++;
		pthread_mutex_unlock(philos[i].meal_lock);
	}
	if (full == philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[0].dead_lock);
		*philos->dead = true;
		pthread_mutex_unlock(philos[0].dead_lock);
		return (1);
	}
	return (0);
}
