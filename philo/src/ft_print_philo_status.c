/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_philo_status.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:24:50 by hyechoi           #+#    #+#             */
/*   Updated: 2021/08/16 20:03:33 by hyechoi          ###   ########.fr       */
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

int	ft_print_philo_status(t_philo *p, char *msg)
{
	int	msglen;

	msglen = ft_strlen(msg);
	while (ft_trylock(&(p->ctx->print_lock)) < 0)
	{
		if (ft_strncmp(msg, MSG_PHILO_DIED, msglen) == 0)
			continue ;
		if (ft_philo_is_dead(p))
			return (-1);
	}
	if (ft_strncmp(msg, MSG_PHILO_DIED, msglen) == 0
		|| !ft_philo_is_dead(p))
		printf("%ldms %d %s", p->ctx->current_timestamp - p->ctx->timestamp,
			p->num, msg);
	if (ft_unlock(&(p->ctx->print_lock)) < 0)
		return (-1);
	return (0);
}
