/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:26:58 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/02/01 16:42:39 by ohosnedl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_error(char *msg)
{
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

static void	thread_error_check(int num)
{
	if (num == 0)
		return ;
	else
		exit_error("Thread error has occured\n");
}

void	safe_thread(pthread_t *thread, void *(*function)(void *), void *data, t_opcode opcode)
{
	if (opcode == CREATE)
		thread_error_check(pthread_create(thread, NULL, function, data));
	else if (opcode == JOIN)
		thread_error_check(pthread_join(*thread, NULL));
	else if (opcode == DETACH)
		thread_error_check(pthread_detach(*thread));
	else
		printf("Wrong thread opcode\n");
}

static void	mutex_error_check(int num)
{
	if (num == 0)
		return ;
	else
		exit_error("Mutex error has occured\n");
}

void	safe_mutex(mtx_t *mutex, t_opcode opcode)
{
	if (opcode == INIT)
		mutex_error_check(pthread_mutex_init(mutex, NULL));
	else if (opcode == LOCK)
		mutex_error_check(pthread_mutex_lock(mutex));
	else if (opcode == UNLOCK)
		mutex_error_check(pthread_mutex_unlock(mutex));
	else if (opcode == DESTROY)
		mutex_error_check(pthread_mutex_destroy(mutex));
	else
		printf("Wrong mutex opcode\n");
}
