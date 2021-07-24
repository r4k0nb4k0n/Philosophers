/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_think.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:20:31 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/25 05:15:47 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Philosopher thinks.
**	Philosopher takes two forks while thinking.
**	Even num philospher takes a left fork, and then takes a right fork.
**	Odd num philosopher takes a right fork, and then takes a left fork.
**
**	@param	t_philo	*p
**	@return	int		status	Return 0 if success.
**							Return -1 if failure.
*/

int	ft_philo_think(t_philo *p)
{
	if (pthread_mutex_lock(p->fork_locks[p->num % 2]) != 0)
		return (-1);
	if (ft_print_philosopher_status(p, MSG_PHILO_TAKEN_FORK) < 0)
		return (-1);
	while (p->fork_locks[LEFT] == p->fork_locks[RIGHT])
	{
		if (p->status == STA_PHILO_DIED)
			return (-1);
	}
	if (pthread_mutex_lock(p->fork_locks[(p->num + 1) % 2]) != 0)
		return (-1);
	if (ft_print_philosopher_status(p, MSG_PHILO_TAKEN_FORK) < 0)
		return (-1);
	return (0);
}
