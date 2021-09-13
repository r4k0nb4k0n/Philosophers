/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_watch_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 21:15:02 by hyechoi           #+#    #+#             */
/*   Updated: 2021/08/21 04:16:31 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_one_of_philos_died(t_philo *p)
{
	int		i;
	t_philo	*q;

	i = 0;
	while (i < p->ctx->num_of_philos)
	{
		q = p + i;
		if (ft_get_timestamp_ms() - q->ctx->time_to_die >= q->timestamp
			&& !ft_philo_is_dead(q))
		{
			q->status = STA_PHILO_DIED;
			q->ctx->killswitch = TRUE;
			ft_print_philo_status(q, MSG_PHILO_DIED);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

int	ft_check_half_of_philos_have_eaten(t_philo *p)
{
	int	ret;
	int	i;
	int	til;

	ret = TRUE;
	if (p->ctx->turn == ODD_LAST)
		i = p->ctx->num_of_philos - 1;
	else
		i = p->ctx->turn;
	if (p->ctx->num_of_philos % 2 == 1
		&& p->ctx->turn == ODD)
		til = p->ctx->num_of_philos - 1;
	else
		til = p->ctx->num_of_philos;
	while (i < til)
	{
		ret &= p[i].is_full;
		i += 2;
	}
	return (ret);
}

void	ft_decide_philos_turn(t_philo *p)
{
	if (p->ctx->num_of_philos % 2 == 1)
		p->ctx->turn = (p->ctx->turn + 1) % 3;
	else
		p->ctx->turn = !(p->ctx->turn);
}

/*
**	Watch philosophers' status.
**
**	@param	void	*philos
**	@return	void	*return
*/

void	*ft_watch_philos(void *philos)
{
	t_philo	*p;

	p = (t_philo *)philos;
	while (p->ctx->num_of_times_each_philo_must_eat == 0
		|| p->ctx->num_of_philos_done_must_eat
		!= p->ctx->num_of_times_each_philo_must_eat)
	{
		if (ft_msleep(4) < 0)
			p->ctx->killswitch = TRUE;
		if (ft_check_one_of_philos_died(p))
			break ;
		/*if (ft_check_half_of_philos_have_eaten(p))
			ft_decide_philos_turn(p);*/
	}
	return (NULL);
}
