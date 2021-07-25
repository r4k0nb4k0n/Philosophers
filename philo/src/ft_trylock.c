/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trylock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 19:21:13 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/25 20:41:07 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Locks mutex.
**	If `is_locked` is TRUE,
**	this will not block waiting for the mutex, but will return -1.
**
**	@param	t_lock	*lock
**	@return	res				Return 0 if success.
**							Return -1 if failure.
*/

int	ft_trylock(t_lock *lock)
{
	if (lock->is_locked)
		return (-1);
	if (pthread_mutex_lock(lock->mutex) < 0)
		return (-1);
	lock->is_locked = TRUE;
	return (0);
}
