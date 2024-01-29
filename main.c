/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:01:29 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/01/29 15:55:43 by ohosnedl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_program		program;
	t_philos		philos[200];
	pthread_mutex_t	forks[200];

	if (ac == 5 || ac == 6)
	{
		program_init(av, &program, philos, forks);
		create_threads(&program, forks);
	}
	else
	{
		printf("Wrong number of arguments\n");
		return (EXIT_FAILURE);
	}
}
