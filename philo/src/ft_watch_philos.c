/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_watch_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 21:15:02 by hyechoi           #+#    #+#             */
/*   Updated: 2021/08/05 16:33:58 by hyechoi          ###   ########.fr       */
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
	ft_unlock(&(p->life_lock));
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
		if (i == 0)
		{
			if (usleep(50) < 0)
				break ;
			num_of_alive = p->ctx->num_of_philos;
		}
		if (ft_check_if_just_one_dead(p, num_of_alive) == 0)
			break ;
		if ((p->life_lock).is_locked == FALSE
			|| p->status == STA_PHILO_DIED)
			num_of_alive--;
		else if (ft_check_if_philo_starve(p + i) == TRUE)
			ft_handle_when_philo_starve(p + i, &num_of_alive);
		i = (i + 1) % p->ctx->num_of_philos;
	}
	return (num_of_alive);
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
	while (i < p->ctx->num_of_philos)
	{
		while (ft_trylock(&((p + i)->life_lock)) == 0
			&& ft_philo_is_dead(p + i))
			return ((void *)(-1));
		i++;
	}
	num_of_alive = ft_check_alive_after_watch_philos(p, p->ctx->num_of_philos);
	i = 0;
	while (i < p->ctx->num_of_philos)
	{
		ft_unlock(&((p + i)->life_lock));
		i++;
	}
	if (num_of_alive == 0)
		return (NULL);
	return ((void *)(-1));
}
