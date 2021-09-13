/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_take_forks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:20:31 by hyechoi           #+#    #+#             */
/*   Updated: 2021/09/13 19:15:21 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_take_fork(t_philo *p, int direction)
{
	while (ft_trylock(p->fork_locks[direction]) < 0)
	{
		if (ft_philo_is_dead(p))
			return (-1);
	}
	if (ft_print_philo_status(p, MSG_PHILO_TAKEN_FORK) < 0)
		return (-1);
	return (0);
}

/*
**	Philosopher takes forks.
**	Philosopher takes two forks.
**	Even num philospher takes a left fork, and then takes a right fork.
**	Odd num philosopher takes a right fork, and then takes a left fork.
**
**	@param	t_philo	*p
**	@return	int		status	Return 0 if success.
**							Return -1 if failure.
*/

int	ft_philo_take_forks(t_philo *p)
{
	if (ft_philo_take_fork(p, LEFT) < 0)
		return (-1);
	while (p->fork_locks[LEFT] == p->fork_locks[RIGHT])
	{
		if (ft_philo_is_dead(p))
			return (-1);
	}
	if (ft_philo_take_fork(p, RIGHT) < 0)
		return (-1);
	return (0);
}
