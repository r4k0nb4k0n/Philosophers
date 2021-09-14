/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_watch_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:02:17 by hyechoi           #+#    #+#             */
/*   Updated: 2021/09/14 15:00:29 by hyechoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_watch_philos(t_context *ctx, t_philo *philos)
{
	int	i;

	while (TRUE)
	{
		i = 0;
		while (i < ctx->num_of_philos)
		{
			if (ft_philo_handle_starve(philos + i))
				return ;
			i++;
		}
		ft_msleep(1);
	}
}
