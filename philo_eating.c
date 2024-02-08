/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:56:44 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/02/05 13:04:38 by ohosnedl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	odd_philo(t_philo *philo)
{
	safe_mutex(philo->left_fork, LOCK);
	print_msg("has taken a fork", philo);
	safe_mutex(philo->right_fork, LOCK);
	print_msg("has taken a fork", philo);
	set_bool(&philo->data->data_lock, &philo->eating, true);
	print_msg("is eating", philo);
	set_int(&philo->data->data_lock, &philo->last_meal_time, gettime());
	ft_usleep(philo->data->time_to_eat);
	set_int(&philo->data->data_lock, &philo->meals_eaten,
		philo->meals_eaten + 1);
	set_bool(&philo->data->data_lock, &philo->eating, false);
	safe_mutex(philo->left_fork, UNLOCK);
	safe_mutex(philo->right_fork, UNLOCK);
}

void	even_philo(t_philo *philo)
{
	safe_mutex(philo->right_fork, LOCK);
	print_msg("has taken a fork", philo);
	safe_mutex(philo->left_fork, LOCK);
	print_msg("has taken a fork", philo);
	set_bool(&philo->data->data_lock, &philo->eating, true);
	print_msg("is eating", philo);
	set_int(&philo->data->data_lock, &philo->last_meal_time, gettime());
	ft_usleep(philo->data->time_to_eat);
	set_int(&philo->data->data_lock, &philo->meals_eaten,
		philo->meals_eaten + 1);
	set_bool(&philo->data->data_lock, &philo->eating, false);
	safe_mutex(philo->right_fork, UNLOCK);
	safe_mutex(philo->left_fork, UNLOCK);
}
