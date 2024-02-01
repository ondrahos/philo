/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters_getters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:22:24 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/02/01 15:35:21 by ohosnedl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool(mtx_t *mutex, bool *dest, bool value)
{
	safe_mutex(mutex, LOCK);
	*dest = value;
	safe_mutex(mutex, UNLOCK);
}

bool	get_bool(mtx_t *mutex, bool *value)
{
	bool	ret;

	safe_mutex(mutex, LOCK);
	ret = *value;
	safe_mutex(mutex, UNLOCK);
	return (ret);
}

void	set_int(mtx_t *mutex, int *dest, int value)
{
	safe_mutex(mutex, LOCK);
	*dest = value;
	safe_mutex(mutex, UNLOCK);
}

int	get_int(mtx_t *mutex, int *value)
{
	int ret;

	safe_mutex(mutex, LOCK);
	ret = *value;
	safe_mutex(mutex, UNLOCK);
	return (ret);
}
