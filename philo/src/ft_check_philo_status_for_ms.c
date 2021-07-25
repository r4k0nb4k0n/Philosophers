/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_philo_status_for_ms.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 04:50:28 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/26 04:55:47 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Check if philo status is expected status for `ms` ms.
**
**	@param	t_philo	*p
**	@param	int		expected
**	@param	long	milliseconds
**	@return	int		res				Return 0 if success
**									Return -1 if expected or failure
*/

int	ft_check_philo_status_for_ms(t_philo *p, int expected, long milliseconds)
{
	long	prev;

	prev = ft_get_timestamp_ms();
	if (prev < 0)
		return (-1);
	while (TRUE)
	{
		if (usleep(100) < 0)
			return (-1);
		if (p->status == expected)
			return (-1);
		if (ft_get_timestamp_ms() - prev >= milliseconds)
			break ;
	}
	return (0);
}
