/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unlock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 19:21:13 by hyechoi           #+#    #+#             */
/*   Updated: 2021/08/12 09:47:50 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Unlocks mutex.
**	After `pthread_mutex_unlock()`, set `is_locked` to FALSE.
**
**	@param	t_lock	*lock
**	@return	res				Return 0 if success.
**							Return -1 if failure.
*/

int	ft_unlock(t_lock *lock)
{
	if (lock->is_locked == TRUE)
	{
		lock->is_locked = FALSE;
		if (pthread_mutex_unlock(lock->mutex) < 0)
			return (-1);
	}
	return (0);
}
