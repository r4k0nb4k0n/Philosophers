/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_take_forks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:20:31 by hyechoi           #+#    #+#             */
/*   Updated: 2021/08/21 05:02:55 by hyechoi          ###   ########.fr       */
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

int	ft_philo_is_my_turn(t_philo *p)
{
	if (p->ctx->turn == ODD_LAST)
		return (p->num == p->ctx->num_of_philos);
	else if (p->ctx->turn == ODD)
	{
		if (p->ctx->num_of_philos % 2 == 1
			&& p->num == p->ctx->num_of_philos)
			return (FALSE);
		return (p->num % 2 == 1);
	}
	else if (p->ctx->turn == EVEN)
		return (p->num % 2 == 0);
	return (FALSE);
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
	/*while (!ft_philo_is_my_turn(p))
	{
		if (ft_philo_is_dead(p))
			return (-1);
	}*/
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
