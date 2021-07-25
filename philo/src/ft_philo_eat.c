/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:44:31 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/25 20:03:14 by hyechoi          ###   ########.fr       */
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
	if (ft_unlock(p->fork_locks[LEFT]) < 0)
		return (-1);
	if (ft_unlock(p->fork_locks[RIGHT]) < 0)
		return (-1);
	if (p->ctx->num_of_times_each_philo_must_eat > 0)
	{
		if (--(p->num_of_times_each_philo_must_eat) == 0)
			p->ctx->num_of_philos_done_must_eat++;
	}
	return (0);
}
