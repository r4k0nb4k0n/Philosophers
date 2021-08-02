/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:48:52 by hyechoi           #+#    #+#             */
/*   Updated: 2021/08/02 17:30:23 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Loop `usleep(100)` `ms` times.
**
**	@param	long		microseconds
**	@return	int			status			Return 0 if success.
**										Return -1 if failure.
*/

int	ft_msleep(long milliseconds)
{
	long	prev;

	prev = ft_get_timestamp_ms();
	if (prev < 0)
		return (-1);
	while (TRUE)
	{
		if (usleep(125) < 0)
			return (-1);
		if (ft_get_timestamp_ms() - prev >= milliseconds)
			break ;
	}
	return (0);
}
