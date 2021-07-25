/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_timestamp_ms.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:34:22 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/25 17:37:12 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_timestamp_ms(void)
{
	t_timeval	timestamp;

	if (gettimeofday(&timestamp, NULL) < 0)
		return (-1);
	return (timestamp.tv_sec * 1000 + timestamp.tv_usec / 1000);
}
