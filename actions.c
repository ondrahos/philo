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

void	one_philo(t_philo *philo)
{
	print_msg("has taken a fork \U0001F374", philo);
	ft_usleep(philo->data->time_to_die);
}

void	eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		safe_mutex(philo->right_fork, LOCK);
		print_msg("has taken a fork \U0001F374", philo);
		safe_mutex(philo->left_fork, LOCK);
		print_msg("has taken a fork \U0001F374", philo);
		set_bool(&philo->data->data_lock, &philo->eating, true);
		print_msg("is eating \U0001F60B", philo);
		set_int(&philo->data->data_lock, &philo->last_meal_time, gettime());
		ft_usleep(philo->data->time_to_eat);
		set_int(&philo->data->data_lock, &philo->meals_eaten, philo->meals_eaten + 1);
		set_bool(&philo->data->data_lock, &philo->eating, false);
		safe_mutex(philo->right_fork, UNLOCK);
		safe_mutex(philo->left_fork, UNLOCK);
	}
	else
	{
		safe_mutex(philo->left_fork, LOCK);
		print_msg("has taken a fork \U0001F374", philo);
		safe_mutex(philo->right_fork, LOCK);
		print_msg("has taken a fork \U0001F374", philo);
		set_bool(&philo->data->data_lock, &philo->eating, true);
		print_msg("is eating \U0001F60B", philo);
		set_int(&philo->data->data_lock, &philo->last_meal_time, gettime());
		ft_usleep(philo->data->time_to_eat);
		set_int(&philo->data->data_lock, &philo->meals_eaten, philo->meals_eaten + 1);
		set_bool(&philo->data->data_lock, &philo->eating, false);
		safe_mutex(philo->left_fork, UNLOCK);
		safe_mutex(philo->right_fork, UNLOCK);
	}
}

void	sleeping(t_philo *philo)
{
	print_msg("is sleeping \U0001F634", philo);
	ft_usleep(philo->data->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	print_msg("is thinking \U0001F914", philo);
}
