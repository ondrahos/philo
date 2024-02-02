/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:47:34 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/02/01 16:44:16 by ohosnedl         ###   ########.fr       */
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

typedef pthread_mutex_t	mtx_t;
typedef struct s_data	t_data;

typedef struct s_philo
{
	int			id;
	int			last_meal_time;
	int			meals_eaten;

	pthread_t	thread;
	mtx_t		*left_fork;
	mtx_t		*right_fork;
	t_data		*data;

	bool		*dead;
	bool		*full;
	bool		eating;
}	t_philo;

typedef struct s_data
{
	int	num_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_meals;
	int	start_time;

	mtx_t	write_lock;
	mtx_t	data_lock;

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

void	init_structs(char **av, t_data *data, t_philo *philo, mtx_t *forks);
int		ft_atoi(const char *str);
int		gettime(void);
void	print_msg(char *msg, t_philo *philo);
void	destroy_all(t_data *data, mtx_t *forks);
void	ft_usleep(int time_to_sleep);
void	create_threads(t_data *data);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
void	eating(t_philo *philo);
void	set_bool(mtx_t *mutex, bool *dest, bool value);
bool	get_bool(mtx_t *mutex, bool *value);
void	set_int(mtx_t *mutex, int *dest, int value);
int		get_int(mtx_t *mutex, int *value);
void	exit_error(char *msg);
void	safe_thread(pthread_t *thread, void *(*function)(void *), void *data, t_opcode opcode);
void	safe_mutex(mtx_t *mutex, t_opcode opcode);
bool	check_dead(t_philo *philo);
bool	check_full(t_philo *philo);
void	one_philo(t_philo *philo);


#endif
