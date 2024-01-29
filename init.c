/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:40:53 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/01/29 15:39:32 by ohosnedl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks_init(pthread_mutex_t *forks, int num)
{
	int	i;

	i = -1;
	while (++i < num)
		pthread_mutex_init(&forks[i], NULL);
}

void	philos_init(char **av, t_program *program,
					t_philos *philos, pthread_mutex_t *forks)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].time_to_die = ft_atoi(av[2]);
		philos[i].time_to_eat = ft_atoi(av[3]);
		philos[i].time_to_sleep = ft_atoi(av[4]);
		if (av[5])
			philos[i].meals_num = ft_atoi(av[5]);
		else
			philos[i].meals_num = -1;
		philos[i].num_of_philos = ft_atoi(av[1]);
		philos[i].last_meal_time = gettime();
		philos[i].start_time = gettime();
		philos[i].dead = &program->dead_flag;
		philos[i].meals_eaten = 0;
		philos[i].eating = 0;
		philos[i].left_fork = &forks[i];
		if (i == 0)
			philos[i].right_fork = &forks[ft_atoi(av[1] - 1)];
		else
			philos[i].right_fork = &forks[i - 1];
		philos[i].write_lock = &program->write_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].dead_lock = &program->dead_lock;
	}
}

void	program_init(char **av, t_program *program,
					t_philos *philos, pthread_mutex_t *forks)
{
	program->dead_flag = false;
	program->philos = philos;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	forks_init(forks, ft_atoi(av[1]));
	philos_init(av, program, philos, forks);
}
