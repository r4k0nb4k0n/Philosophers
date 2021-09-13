/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_is_starving.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 04:02:32 by hyechoi           #+#    #+#             */
/*   Updated: 2021/08/21 04:07:05 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_is_starving(t_philo *p)
{
	return (ft_get_timestamp_ms() - p->timestamp >= p->ctx->time_to_die);
}
