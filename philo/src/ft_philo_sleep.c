/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_sleep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:44:31 by hyechoi           #+#    #+#             */
/*   Updated: 2021/08/12 10:52:08 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Philosopher sleeps during TIME_TO_SLEEP ms.
**
**	@param	t_philo	*p
**	@return	int		status	Return 0 if success.
**							Return -1 if failure.
*/

int	ft_philo_sleep(t_philo *p)
{
	if (ft_print_philo_status(p, MSG_PHILO_SLEEPING) < 0)
		return (-1);
	if (ft_check_philo_status_for_ms(p, p->ctx->time_to_sleep) < 0)
		return (-1);
	p->is_full = FALSE;
	return (0);
}
