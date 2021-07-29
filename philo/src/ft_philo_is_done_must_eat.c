/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_is_done_must_eat.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 18:27:55 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/29 20:08:56 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_is_done_must_eat(t_philo *p)
{
	return (p->ctx->num_of_times_each_philo_must_eat > 0
		&& p->num_of_times_each_philo_must_eat <= 0);
}
