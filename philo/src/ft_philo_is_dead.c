/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_is_dead.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:00:01 by hyechoi           #+#    #+#             */
/*   Updated: 2021/08/16 20:03:07 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_is_dead_suddenly(t_philo *p)
{
	return (p->status == STA_PHILO_DIED);
}

int	ft_philo_is_dead(t_philo *p)
{
	return (p->ctx->killswitch == TRUE
		|| p->status == STA_PHILO_DIED);
}
