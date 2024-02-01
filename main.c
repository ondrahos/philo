/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:48:07 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/02/01 16:41:50 by ohosnedl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	philo[200];
	t_data	data;
	mtx_t	forks[200];

	if (ac == 5 || ac == 6)
	{
		init_structs(av, &data, philo, forks);
		create_threads(&data);
		destroy_all(&data, forks);
	}
	else
	{
		printf("Wrong number of arguments\n");
		return (EXIT_FAILURE);
	}
}
