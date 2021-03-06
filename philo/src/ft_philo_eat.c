/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:44:31 by hyechoi           #+#    #+#             */
/*   Updated: 2021/09/15 15:08:53 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_check_must_eat(t_philo *p)
{
	if (p->ctx->num_of_times_each_philo_must_eat > 0
		&& --(p->num_of_times_each_philo_must_eat) == 0)
	{
		p->ctx->num_of_philos_done_must_eat++;
		if (p->ctx->num_of_philos_done_must_eat == p->ctx->num_of_philos)
		{
			p->ctx->killswitch = TRUE;
			ft_print_alert(&(p->ctx->print_lock),
				MSG_PHILO_FINISHED_MUST_EAT);
		}
	}
}

/*
**	Philosopher eats.
**	Philosopher keeps its forks during TIME_TO_EAT ms.
**
**	@param	t_philo	*p
**	@return	int		status	Return 0 if success.
**							Return -1 if failure.
*/

int	ft_philo_eat(t_philo *p)
{
	while (ft_trylock(&(p->eat_lock)) < 0)
	{
		if (ft_philo_is_dead(p))
			return (TRUE);
		usleep(100);
	}
	p->timestamp = ft_get_timestamp_ms();
	p->is_full = TRUE;
	ft_unlock(&(p->eat_lock));
	if (ft_print_philo_status(p, MSG_PHILO_EATING) < 0)
		return (-1);
	if (ft_check_philo_status_for_ms(p, p->ctx->time_to_eat) < 0)
		return (-1);
	ft_philo_check_must_eat(p);
	return (0);
}
