/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:18:43 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/02/05 13:15:20 by ohosnedl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	one_philo(t_philo *philo)
{
	print_msg("has taken a fork", philo);
	ft_usleep(philo->data->time_to_die);
}

void	eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
		even_philo(philo);
	else
		odd_philo(philo);
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
