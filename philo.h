/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:47:34 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/02/05 13:06:10 by ohosnedl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>

typedef pthread_mutex_t	t_mtx;
typedef struct s_data	t_data;

typedef struct s_philo
{
	int			id;
	int			last_meal_time;
	int			meals_eaten;

	pthread_t	thread;
	t_mtx		*left_fork;
	t_mtx		*right_fork;
	t_data		*data;

	bool		*dead;
	bool		*full;
	bool		eating;
}	t_philo;

typedef struct s_data
{
	int		num_of_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_of_meals;
	int		start_time;

	t_mtx	write_lock;
	t_mtx	data_lock;

	bool	dead_flag;
	bool	full_flag;

	t_philo	*philo;
}	t_data;

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_opcode;

void	init_structs(char **av, t_data *data, t_philo *philo, t_mtx *forks);
int		ft_atoi(const char *str);
int		gettime(void);
void	print_msg(char *msg, t_philo *philo);
void	destroy_all(t_data *data, t_mtx *forks);
void	ft_usleep(int time_to_sleep);
void	create_threads(t_data *data);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
void	eating(t_philo *philo);
void	set_bool(t_mtx *mutex, bool *dest, bool value);
bool	get_bool(t_mtx *mutex, bool *value);
void	set_int(t_mtx *mutex, int *dest, int value);
int		get_int(t_mtx *mutex, int *value);
void	exit_error(char *msg);
void	safe_thread(pthread_t *thread, void *(*function)(void *),
			void *data, t_opcode opcode);
void	safe_mutex(t_mtx *mutex, t_opcode opcode);
bool	check_dead(t_philo *philo);
bool	check_full(t_philo *philo);
void	one_philo(t_philo *philo);
void	check_args(char **av, int ac);
void	odd_philo(t_philo *philo);
void	even_philo(t_philo *philo);

#endif
