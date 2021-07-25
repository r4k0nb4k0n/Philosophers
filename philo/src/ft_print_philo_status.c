/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_philo_status.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:24:50 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/25 21:24:05 by hyechoi          ###   ########.fr       */
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

int		ft_print_philo_status(t_philo *p, char *msg)
{
	long	curr;

	while (ft_trylock(&(p->ctx->print_lock)) < 0)
	{
		if (ft_philo_is_dead(p))
			return (-1);
	}
	curr = ft_get_timestamp_ms();
	if (curr < 0)
		return (-1);
	printf("%ldms %d %s", curr - p->ctx->timestamp, p->num, msg);
	if (ft_unlock(&(p->ctx->print_lock)) < 0)
		return (-1);
	return (0);
}
