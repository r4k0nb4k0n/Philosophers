/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_philosopher_status.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:24:50 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/24 21:25:23 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Print philosopher's status.
**
**	@param	t_philo	*philo
**	@param	char	*msg
**	@return	int		res		Return 0 if success
**							Return -1 if failure
*/

int		ft_print_philosopher_status(t_philo *p, char *msg)
{
	t_timeval	current_timestamp;
	long		elapsed;

	if (pthread_mutex_lock(&(p->ctx->print_lock)) < 0)
		return (-1);
	if (gettimeofday(&current_timestamp, NULL) < 0)
		return (-1);
	elapsed = ft_calc_elapsed_timeval(p->ctx->timestamp, current_timestamp);
	printf("%ldms %d %s", elapsed, p->num, msg);
	if (pthread_mutex_unlock(&(p->ctx->print_lock)) < 0)
		return (-1);
	return (0);
}
