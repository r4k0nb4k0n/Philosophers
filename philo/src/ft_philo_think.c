/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_think.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:20:31 by hyechoi           #+#    #+#             */
/*   Updated: 2021/08/08 18:10:04 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Philosopher thinks.
**	Philosopher takes two forks while thinking.
**
**	@param	t_philo	*p
**	@return	int		status	Return 0 if success.
**							Return -1 if failure.
*/

int	ft_philo_think(t_philo *p)
{
	if (ft_print_philo_status(p, MSG_PHILO_THINKING) < 0)
		return (-1);
	return (ft_philo_take_forks(p));
}
