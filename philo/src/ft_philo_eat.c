/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:44:31 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/25 00:21:26 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Philosopher eats.
**	Philosopher keeps its forks during TIME_TO_EAT ms.
**	After TIME_TO_EAT ms, philosopher drop its forks
**
**	@param	t_philo	*p
**	@return	int		status	Return 0 if success.
**							Return -1 if failure.
*/

int	ft_philo_eat(t_philo *p)
{
	if (ft_msleep(p->ctx->time_to_eat) < 0)
		return (-1);
	if (pthread_mutex_unlock(p->fork_locks[p->num % 2]) < 0)
		return (-1);
	if (pthread_mutex_unlock(p->fork_locks[(p->num + 1) % 2]) < 0)
		return (-1);
	if (p->ctx->num_of_times_each_philo_must_eat > 0)
	{
		p->num_of_times_each_philo_must_eat--;
		if (p->num_of_times_each_philo_must_eat <= 0)
			p->status = STA_PHILO_DIED;
	}
	return (0);
}
