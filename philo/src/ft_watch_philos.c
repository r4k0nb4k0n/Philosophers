/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_watch_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 21:15:02 by hyechoi           #+#    #+#             */
/*   Updated: 2021/08/13 16:42:38 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
			return ((void *)(-1));
		if (ft_check_half_of_philos_have_eaten(p))
		{
			if (p->ctx->num_of_philos % 2 == 1)
				p->ctx->turn = (p->ctx->turn + 1) % 3;
			else
				p->ctx->turn = !(p->ctx->turn);
		}
		if (usleep(100) < 0)
			break ;
	}
	return (NULL);
}
