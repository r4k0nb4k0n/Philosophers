/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_is_dead.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:00:01 by hyechoi           #+#    #+#             */
/*   Updated: 2021/08/10 07:53:00 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_is_dead_suddenly(t_philo *p)
{
	return (p->status == STA_PHILO_DIED
		&& (p->ctx->num_of_times_each_philo_must_eat == 0
			|| !ft_philo_is_done_must_eat(p)));
}

int	ft_philo_is_dead(t_philo *p)
{
	if (ft_get_timestamp_ms() - p->ctx->time_to_die >= p->timestamp)
	{
		p->status = STA_PHILO_DIED;
		p->ctx->killswitch = TRUE;
	}
	return (p->ctx->killswitch == TRUE
		|| p->status == STA_PHILO_DIED
		|| (p->ctx->num_of_times_each_philo_must_eat > 0
			&& p->ctx->num_of_philos == p->ctx->num_of_philos_done_must_eat));
}
