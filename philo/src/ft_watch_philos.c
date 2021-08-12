/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_watch_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 21:15:02 by hyechoi           #+#    #+#             */
/*   Updated: 2021/08/12 19:28:32 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Handle when target philosopher starves.
*/

int	ft_check_if_philo_starve(t_philo *p)
{
	long	elapsed;
	long	prev_ts;

	prev_ts = p->timestamp;
	elapsed = ft_get_timestamp_ms();
	if (elapsed < 0)
		return (FALSE);
	elapsed -= prev_ts;
	return (elapsed > p->ctx->time_to_die);
}

void	ft_handle_when_philo_starve(t_philo *p, int *num_of_alive)
{
	p->status = STA_PHILO_DIED;
	ft_unlock(&(p->act_lock));
	if (p->ctx->num_of_times_each_philo_must_eat == 0)
		p->ctx->killswitch = TRUE;
	*num_of_alive -= 1;
}

int	ft_check_if_just_one_dead(t_philo *p, int num_of_alive)
{
	if (p->ctx->num_of_philos > num_of_alive)
		return (0);
	return (-1);
}

int	ft_check_alive_after_watch_philos(t_philo *p, int num_of_alive)
{
	int	i;

	i = 0;
	while (p->ctx->num_of_times_each_philo_must_eat == 0
		|| p->ctx->num_of_philos_done_must_eat
		!= p->ctx->num_of_times_each_philo_must_eat)
	{
		i = (i + 1) % p->ctx->num_of_philos;
	}
	return (num_of_alive);
}

int	ft_check_half_of_philos_have_eaten(t_philo *p)
{
	int	ret;
	int	i;

	ret = TRUE;
	if (p->ctx->turn == ODD_LAST)
		i = p->ctx->num_of_philos - 1;
	else
		i = p->ctx->turn;
	while (i < p->ctx->num_of_philos)
	{
		if (p->ctx->num_of_philos % 2 == 1
			&& p->ctx->turn != ODD_LAST
			&& i == p->ctx->num_of_philos - 1)
			break ;
		ret &= p[i].is_full;
		i += 2;
	}
	return (ret);
}

/*
**	Watch philosophers' status.
**
**	@param	void	*philos
**	@return	void	*return
*/

void	*ft_watch_philos(void *philos)
{
	t_philo		*p;
	int			i;

	p = (t_philo *)philos;
	i = 0;
	while (p->ctx->num_of_times_each_philo_must_eat == 0
		|| p->ctx->num_of_philos_done_must_eat
		!= p->ctx->num_of_times_each_philo_must_eat)
	{
		if (ft_philo_is_dead(p))
			break ;
		if (usleep(50) < 0)
			break ;
		if (ft_check_half_of_philos_have_eaten(p))
		{
			if (p->ctx->num_of_philos % 2 == 1)
				p->ctx->turn = (p->ctx->turn + 1) % 3;
			else
				p->ctx->turn = !(p->ctx->turn);
		}
	}
	return ((void *)(-1));
}
