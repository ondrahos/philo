/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:18:43 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/02/01 16:37:58 by ohosnedl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	if (philo->data->num_of_philos == 1)
		return (ft_usleep(philo->data->time_to_eat));
	if (philo->id % 2 == 0)
	{
		safe_mutex(philo->right_fork, LOCK);
		print_msg("has taken a fork", philo);
		safe_mutex(philo->left_fork, LOCK);
		print_msg("has taken a fork", philo);
		set_bool(&philo->data->data_lock, &philo->eating, true);
		print_msg("is eating", philo);
		set_int(&philo->data->data_lock, &philo->last_meal_time, gettime());
		set_int(&philo->data->data_lock, &philo->meals_eaten, philo->meals_eaten + 1);
		ft_usleep(philo->data->time_to_eat);
		set_bool(&philo->data->data_lock, &philo->eating, false);
		safe_mutex(philo->right_fork, UNLOCK);
		safe_mutex(philo->left_fork, UNLOCK);
	}
	else
	{
		safe_mutex(philo->left_fork, LOCK);
		print_msg("has taken a fork", philo);
		safe_mutex(philo->right_fork, LOCK);
		print_msg("has taken a fork", philo);
		set_bool(&philo->data->data_lock, &philo->eating, true);
		print_msg("is eating", philo);
		set_int(&philo->data->data_lock, &philo->last_meal_time, gettime());
		set_int(&philo->data->data_lock, &philo->meals_eaten, philo->meals_eaten + 1);
		ft_usleep(philo->data->time_to_eat);
		set_bool(&philo->data->data_lock, &philo->eating, false);
		safe_mutex(philo->left_fork, UNLOCK);
		safe_mutex(philo->right_fork, UNLOCK);
	}
}

void	sleeping(t_philo *philo)
{
	print_msg("is sleeping", philo);
	ft_usleep(philo->data->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	print_msg("is thinking", philo);
}
