/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_handle_starve.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:01:51 by hyechoi           #+#    #+#             */
/*   Updated: 2021/09/15 15:08:47 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_handle_starve(t_philo *p)
{
	while (ft_trylock(&(p->eat_lock)) < 0)
	{
		if (ft_philo_is_dead(p))
			return (TRUE);
		usleep(100);
	}
	if (ft_philo_is_starving(p))
	{
		p->ctx->killswitch = TRUE;
		p->status = STA_PHILO_DIED;
		ft_print_philo_status(p, MSG_PHILO_DIED);
	}
	ft_unlock(&(p->eat_lock));
	return (ft_philo_is_dead(p));
}
