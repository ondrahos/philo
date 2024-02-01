/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:10:46 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/02/01 16:40:08 by ohosnedl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo(t_philo *philo, t_data *data, mtx_t *forks)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
	{
		philo[i].id = i + 1;
		philo[i].last_meal_time = 0;
		philo[i].meals_eaten = 0;
		philo[i].left_fork = &forks[i];
		if (i == 0)
			philo[i].right_fork = &forks[data->num_of_philos - 1];
		else
			philo[i].right_fork = &forks[i - 1];
		philo[i].data = data;
		philo[i].dead = &data->dead_flag;
		philo[i].full = &data->full_flag;
		philo[i].eating = false;
	}
}

static void	init_data(t_data *data, t_philo *philo, char **av)
{
	data->num_of_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->num_of_meals = ft_atoi(av[5]);
	else
		data->num_of_meals = -1;
	data->start_time = gettime();
	safe_mutex(&data->write_lock, INIT);
	safe_mutex(&data->data_lock, INIT);
	data->dead_flag = false;
	data->full_flag = false;
	data->philo = philo;
}

static void	init_forks(mtx_t *forks, int num_of_forks)
{
	int	i;

	i = -1;
	while (++i < num_of_forks)
		safe_mutex(&forks[i], INIT);
}

void	init_structs(char **av, t_data *data, t_philo *philo, mtx_t *forks)
{
	init_forks(forks, ft_atoi(av[1]));
	init_data(data, philo, av);
	init_philo(philo, data, forks);
}
