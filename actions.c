/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:36:14 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/01/31 15:59:35 by ohosnedl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philos *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_msg("has taken a fork", philo, philo->id);
	if (philo->num_of_philos == 1)
	{
		ft_usleep(philo->time_to_eat);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	print_msg("has taken a fork", philo, philo->id);
	philo->eating = 1;
	print_msg("is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal_time = gettime();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleeping(t_philos *philo)
{
	print_msg("is sleeping", philo, philo->id);
	ft_usleep(philo->time_to_sleep);
}

void	thinking(t_philos *philo)
{
	print_msg("is thinking", philo, philo->id);
}
