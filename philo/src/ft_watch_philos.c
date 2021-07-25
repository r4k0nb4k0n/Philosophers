/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_watch_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 21:15:02 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/25 18:34:24 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Handle when target philosopher starves.
*/

int		ft_check_if_philo_starve(t_philo *p)
{
	volatile long	curr;

	curr = ft_get_timestamp_ms();
	if (curr < 0)
		return (-1);
	return ((curr - p->timestamp) > p->ctx->time_to_die
			&& p->status == STA_PHILO_THINKING);
}

void	ft_handle_when_philo_starve(t_philo *p)
{
	p->status = STA_PHILO_DIED;
	if (p->ctx->num_of_times_each_philo_must_eat == 0)
		p->ctx->killswitch = TRUE;
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
			num_of_alive = p->ctx->num_of_philos;
		if (p->status == STA_PHILO_DIED
			|| ft_philo_is_done_must_eat(p))
			num_of_alive--;
		else if (ft_check_if_philo_starve(p + i) == TRUE)
			ft_handle_when_philo_starve(p + i);
		i = (i + 1) % p->ctx->num_of_philos;
	}
	if (num_of_alive == 0)
		return (NULL);
	return ((void *)(-1));
}
