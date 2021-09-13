/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_drop_forks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:44:31 by hyechoi           #+#    #+#             */
/*   Updated: 2021/08/21 05:03:11 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Philosopher drops forks.
**	Philosopher drops two forks.
**	Even num philospher drops a left fork, and then drops a right fork.
**	Odd num philosopher drops a right fork, and then drops a left fork.
**
**	@param	t_philo	*p
**	@return	int		status	Return 0 if success.
**							Return -1 if failure.
*/

int	ft_philo_drop_forks(t_philo *p)
{
	if (ft_unlock(p->fork_locks[LEFT]) < 0)
		return (-1);
	if (ft_unlock(p->fork_locks[RIGHT]) < 0)
		return (-1);
	return (0);
}
