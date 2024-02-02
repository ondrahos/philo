/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:12:04 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/02/01 16:42:14 by ohosnedl         ###   ########.fr       */
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

void	print_msg(char *msg, t_philo *philo)
{
	int	time;

	safe_mutex(&philo->data->write_lock, LOCK);
	time = gettime() - philo->data->start_time;
	if (get_bool(&philo->data->data_lock, philo->full) ||
		get_bool(&philo->data->data_lock, philo->dead))
			return (safe_mutex(&philo->data->write_lock, UNLOCK));
	printf("%i %i %s\n", time, philo->id, msg);
	safe_mutex(&philo->data->write_lock, UNLOCK);
}

void	destroy_all(t_data *data, mtx_t *forks)
{
	int	i;

	i = -1;
	safe_mutex(&data->write_lock, DESTROY);
	safe_mutex(&data->data_lock, DESTROY);
	while (++i < data->num_of_philos)
		safe_mutex(&forks[i], DESTROY);
}

void	ft_usleep(int time_to_sleep)
{
	int	start;

	start = gettime();
	while ((gettime() - start) < time_to_sleep)
		usleep(500);
}
