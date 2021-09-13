/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_philo_life.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:57:27 by hyechoi           #+#    #+#             */
/*   Updated: 2021/09/13 21:31:14 by hyechoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Clean philosopher's life.
**	Drop philosopher's forks.
**	Unlock philosopher's vital_lock.
**
**	@param	t_philo	*p
**	@return	int		res	Return 0 if success
**						Return -1 if failure
*/

int	ft_clean_philo_life(t_philo *p)
{
	if (ft_philo_drop_forks(p) < 0)
		return (-1);
	if (ft_unlock(&(p->vital_lock)) < 0)
		return (-1);
	return (0);
}

/*
**	Loop philosopher's life.
**	0. Philosopher takes two forks.
**	1. Philosopher eats.
**	2. Philosopher drops two forks.
**	3. Philosopher sleeps.
**	4. Philosopher thinks.
**		4.1. Philosopher takes two forks while thinking.
**	5. Go to 1.
**	Philosopher stops when die, done must eat, killswitch on.
**
**	@param	t_philo	*p
**	@return	int		res	Return 0 if success
**						Return -1 if timestamp failure
*/

int	ft_loop_philo_life(t_philo *p)
{
	p->timestamp = ft_get_timestamp_ms();
	p->is_full = FALSE;
	if (p->num % 2 == 1)
		ft_msleep(1);
	if (ft_philo_take_forks(p) < 0)
		return (0);
	while (TRUE)
	{
		if (ft_philo_eat(p) < 0)
			break ;
		if (ft_philo_drop_forks(p) < 0)
			break ;
		if (ft_philo_sleep(p) < 0)
			break ;
		if (ft_philo_think(p) < 0)
			break ;
	}
	return (0);
}

/*
**	Run philosopher's life.
**	1. Loop philo life.
**	2. If died, print dying message.
**	3. Clean philo life.
**	4.
**
**	@param	void	*philo
**	@return	void	*		NULL if loop stops normally
**							(void *)(-1) if error occured
*/

void	*ft_run_philo_life(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (ft_loop_philo_life(p) < 0)
		return ((void *)(-1));
	if (ft_msleep(100) < 0)
		return ((void *)(-1));
	if (ft_clean_philo_life(p) < 0)
		return ((void *)(-1));
	if (ft_philo_is_dead_suddenly(p))
		return ((void *)(-1));
	return (NULL);
}
