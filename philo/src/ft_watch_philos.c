/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_watch_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 21:15:02 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/26 05:18:12 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Handle when target philosopher starves.
*/

int		ft_check_if_philo_starve(t_philo *p)
{
	long	elapsed;
	long	prev_ts;

	prev_ts = p->timestamp;
	elapsed = ft_get_timestamp_ms();
	if (elapsed < 0)
		return (FALSE);
	elapsed -= prev_ts;
	return (elapsed >= p->ctx->time_to_die);
}

void	ft_handle_when_philo_starve(t_philo *p, int *num_of_alive)
{
	p->status = STA_PHILO_DIED;
	if (p->ctx->num_of_times_each_philo_must_eat == 0)
		p->ctx->killswitch = TRUE;
	*num_of_alive -= 1;
}

int		ft_check_if_just_one_dead_when_unlimited(t_philo *p, int num_of_alive)
{
	if (p->ctx->num_of_times_each_philo_must_eat == 0
		&& p->ctx->num_of_philos == num_of_alive + 1)
		return (0);
	return (-1);
}

/*
**	Watch philosophers' status.
**	Loop below:
**	1. If `i`th philosopher's elapsed time after start thinking/eating is bigger
**		than TIME_TO_DIE,
**		1.1. Set the philosopher's state to STA_PHILO_DIED.
**		1.2. If ctx->num_of_times_each_philo_must_eat >= 1, continue.
**		1.3. Else Turn killswitch on and kill everyone.
**
**	@param	void	*philos
**	@return	void	*return
*/

void	*ft_watch_philos(void *philos)
{
	t_philo		*p;
	int			i;
	int			num_of_alive;

	p = (t_philo *)philos;
	i = 0;
	num_of_alive = p->ctx->num_of_philos;
	while (num_of_alive > 0)
	{
		if (i == 0)
		{
			ft_msleep(5);
			num_of_alive = p->ctx->num_of_philos;
		}
		if (ft_check_if_just_one_dead_when_unlimited(p, num_of_alive) == 0)
			break ;
		if (p->status == STA_PHILO_DIED || ft_philo_is_done_must_eat(p))
			num_of_alive--;
		else if (ft_check_if_philo_starve(p + i) == TRUE)
			ft_handle_when_philo_starve(p + i, &num_of_alive);
		i = (i + 1) % p->ctx->num_of_philos;
	}
	if (num_of_alive == 0)
		return (NULL);
	return ((void *)(-1));
}
