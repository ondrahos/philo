/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:02:56 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/01/29 16:00:12 by ohosnedl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	is_neg;
	int	res;

	i = 0;
	is_neg = 1;
	res = 0;
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * is_neg);
}

int	gettime(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("gettimeofday error\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_msg(char *msg, t_philos *philo, int id)
{
	int	time;

	pthread_mutex_lock(philo->write_lock);
	time = gettime() - philo->start_time;
	if (!dead_loop(philo))
		printf("%i %i %s\n", time, id, msg);
	pthread_mutex_unlock(philo->write_lock);
}

void	destroy_all(char *msg, t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = -1;
	if (msg)
		printf("%s\n", msg);
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->dead_lock);
	while (++i < program->philos[0].num_of_philos)
		pthread_mutex_destroy(&forks[i]);
}

void	ft_usleep(int time_to_sleep)
{
	int	start;

	start = gettime();
	while ((gettime() - start) < time_to_sleep)
		usleep(500);
}
