/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_philo_life.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:57:27 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/26 00:43:19 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Set act, threshold, msg according to philospher's status.
**
**	@param	t_philo		*p
**	@param	int			*(*act)(t_philo *)
**	@param	char		**msg
**	@return	void							Nothing.
*/

void	ft_set_params_by_philo_status(t_philo *p, int (**act)(t_philo *),
		char **msg)
{
	if (p->status == STA_PHILO_THINKING)
	{
		*msg = MSG_PHILO_THINKING;
		*act = &ft_philo_think;
	}
	else if (p->status == STA_PHILO_EATING)
	{
		*msg = MSG_PHILO_EATING;
		*act = &ft_philo_eat;
	}
	else if (p->status == STA_PHILO_SLEEPING)
	{
		*msg = MSG_PHILO_SLEEPING;
		*act = &ft_philo_sleep;
	}
}

/*
**	Run philosopher's life with a loop of this process:
**	1. X is thinking.
**		1.1. X has taken two forks.
**	2. X is eating.
**	3. X is sleeping.
**	X dies when starving.
**
**	@param	void	*philo
**	@return	void	*		Nothing.
*/

void	*ft_run_philo_life(void *philo)
{
	t_philo		*p;
	int			(*act)(t_philo *);
	char		*msg;

	p = (t_philo *)philo;
	p->timestamp = ft_get_timestamp_ms();
	if (p->timestamp < 0)
		return ((void *)(-1));
	while (!ft_philo_is_dead(p))
	{
		ft_set_params_by_philo_status(p, &act, &msg);
		if (ft_philo_is_dead(p) || ft_print_philo_status(p, msg) < 0)
			break ;
		if (ft_philo_is_dead(p) || act(p) < 0)
			break ;
		if (!ft_philo_is_dead(p))
			p->status = (p->status + 1) % 3;
	}
	if (ft_philo_drop_forks(p) < 0)
		return ((void *)(-1));
	if ((p->status == STA_PHILO_DIED
		&& ft_print_philo_status(p, MSG_PHILO_DIED) < 0)
		|| ft_philo_is_dead_suddenly(p))
		return ((void *)(-1));
	return (NULL);
}
