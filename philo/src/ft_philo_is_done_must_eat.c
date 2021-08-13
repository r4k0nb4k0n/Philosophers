/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_is_done_must_eat.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 18:27:55 by hyechoi           #+#    #+#             */
/*   Updated: 2021/08/13 14:42:45 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_is_done_must_eat(t_philo *p)
{
	return (p->ctx->num_of_times_each_philo_must_eat > 0
		&& p->ctx->num_of_philos_done_must_eat == p->ctx->num_of_philos);
}
