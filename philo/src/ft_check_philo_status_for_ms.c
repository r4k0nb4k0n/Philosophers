/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_philo_status_for_ms.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 04:50:28 by hyechoi           #+#    #+#             */
/*   Updated: 2021/08/21 03:40:17 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Check if philo status is expected status for `ms` ms.
**
**	@param	t_philo	*p
**	@param	long	milliseconds
**	@return	int		res				Return 0 if success
**									Return -1 if expected or failure
*/

int	ft_check_philo_status_for_ms(t_philo *p, long milliseconds)
{
	long	threshold;

	threshold = ft_get_timestamp_ms() + milliseconds;
	while (ft_get_timestamp_ms() < threshold)
	{
		if (ft_philo_is_dead(p))
			return (-1);
		if (usleep(50) < 0)
			return (-1);
	}
	return (0);
}
