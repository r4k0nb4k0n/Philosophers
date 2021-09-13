/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_is_dead.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:00:01 by hyechoi           #+#    #+#             */
/*   Updated: 2021/08/21 04:33:37 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_is_dead_suddenly(t_philo *p)
{
	return (p->status == STA_PHILO_DIED);
}

int	ft_philo_is_dead(t_philo *p)
{
	while (ft_trylock(&(p->vital_lock)) < 0)
	{
		if (p->ctx->killswitch || p->status == STA_PHILO_DIED)
			return (TRUE);
	}
	if (ft_philo_is_starving(p))
	{
		p->ctx->killswitch = TRUE;
		p->status = STA_PHILO_DIED;
		ft_print_philo_status(p, MSG_PHILO_DIED);
	}
	ft_unlock(&(p->vital_lock));
	return (p->ctx->killswitch || p->status == STA_PHILO_DIED);
}
