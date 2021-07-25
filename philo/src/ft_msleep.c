/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:48:52 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/25 20:55:15 by hyechoi          ###   ########.fr       */
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
	volatile long	prev;
	volatile long	curr;

	prev = ft_get_timestamp_ms();
	if (prev < 0)
		return (-1);
	while (TRUE)
	{
		usleep(199);
		curr = ft_get_timestamp_ms();
		if (curr - prev >= milliseconds)
			break ;
	}
	return (0);
}
