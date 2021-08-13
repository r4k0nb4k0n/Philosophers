/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_is_dead.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:00:01 by hyechoi           #+#    #+#             */
/*   Updated: 2021/08/13 17:05:59 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_is_dead_suddenly(t_philo *p)
{
	return (p->status == STA_PHILO_DIED);
}

int	ft_philo_is_dead(t_philo *p)
{
	if (p->ctx->current_timestamp - p->ctx->time_to_die >= p->timestamp
		&& (p->status != STA_PHILO_DIED && p->ctx->killswitch != TRUE))
	{
		p->status = STA_PHILO_DIED;
		p->ctx->killswitch = TRUE;
		ft_print_philo_status(p, MSG_PHILO_DIED);
	}
	return (p->ctx->killswitch == TRUE
		|| p->status == STA_PHILO_DIED);
}
