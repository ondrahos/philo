/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:58:03 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/02/05 13:01:33 by ohosnedl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_dead(t_philo *philo)
{
	int		last_meal;
	bool	eating;

	last_meal = get_int(&philo->data->data_lock, &philo->last_meal_time);
	eating = get_bool(&philo->data->data_lock, &philo->eating);
	if (gettime() - last_meal > philo->data->time_to_die && eating == false)
		return (true);
	return (false);
}

bool	check_dead(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->num_of_philos)
	{
		if (philo_dead(&philo[i]) == true)
		{
			print_msg("died", &philo[i]);
			set_bool(&philo->data->data_lock, philo[i].dead, true);
			return (true);
		}
	}
	return (false);
}

bool	check_full(t_philo *philo)
{
	int	i;
	int	full;

	i = -1;
	full = 0;
	if (philo[0].data->num_of_meals == -1)
		return (false);
	while (++i < philo->data->num_of_philos)
	{
		if (philo[i].data->num_of_meals <= get_int(&philo[i].data->data_lock,
				&philo[i].meals_eaten))
			full++;
	}
	if (full == philo[0].data->num_of_philos)
	{
		set_bool(&philo->data->data_lock, philo[0].full, true);
		return (true);
	}
	return (false);
}

void	check_args(char **av, int ac)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (!ft_atoi(av[i]))
		{
			printf("Arguments have to be numbers\n");
			exit(EXIT_FAILURE);
		}
		if (ft_atoi(av[i]) <= 0)
		{
			printf("Arguments cannot be less than or equal to zero\n");
			exit(EXIT_FAILURE);
		}
	}
}
