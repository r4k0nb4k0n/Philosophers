/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:48:52 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/25 05:16:28 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Loop `usleep(100)` `ms` times.
**
**	@param	useconds_t	microseconds
**	@return	int			status			Return 0 if success.
**										Return -1 if failure.
*/

int	ft_msleep(useconds_t milliseconds)
{
	t_timeval	prev;
	t_timeval	curr;
	useconds_t	gap;

	if (gettimeofday(&prev, NULL) < 0)
		return (-1);
	while (TRUE)
	{
		if (gettimeofday(&curr, NULL) < 0)
			return (-1);
		gap = (curr.tv_sec - prev.tv_sec) * 1000
			+ (curr.tv_usec - prev.tv_usec) / 1000;
		if (gap >= milliseconds)
			break ;
	}
	return (0);
}
