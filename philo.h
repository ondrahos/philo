/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:50:29 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/01/29 16:00:25 by ohosnedl         ###   ########.fr       */
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

typedef struct s_philos
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*dead_lock;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				last_meal_time;
	int				start_time;
	bool			*dead;
	int				meals_num;
	int				meals_eaten;
	int				eating;
	int				num_of_philos;
}	t_philos;

typedef struct s_program
{
	bool			dead_flag;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	dead_lock;
	t_philos		*philos;
}	t_program;

int		dead_loop(t_philos *philo);
void	*philo_routine(void *pointer);
void	*monitor(void	*pointer);
void	create_threads(t_program *program, pthread_mutex_t *forks);
int		check_full(t_philos *philos);
int		check_dead(t_philos *philos);
int		philo_dead(t_philos *philo, int time_to_die);
void	forks_init(pthread_mutex_t *forks, int num);
void	philos_init(char **av, t_program *program,t_philos *philos, pthread_mutex_t *forks);
void	program_init(char **av, t_program *program, t_philos *philos, pthread_mutex_t *forks);
void	print_msg(char *msg, t_philos *philo, int id);
int		gettime(void);
int		ft_atoi(const char *str);
void	destroy_all(char *msg, t_program *program, pthread_mutex_t *forks);

#endif
