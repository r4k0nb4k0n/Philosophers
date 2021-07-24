/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:25:10 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/25 01:15:06 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		ft_init_philos(t_philo **philos, t_context *ctx,
		pthread_mutex_t *fork_locks)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * ctx->num_of_philos);
	if (*philos == NULL)
		return (-1);
	i = 0;
	while (i < ctx->num_of_philos)
	{
		(*philos + i)->num = i + 1;
		(*philos + i)->ctx = ctx;
		(*philos + i)->num_of_times_each_philo_must_eat
		= ctx->num_of_times_each_philo_must_eat;
		if (gettimeofday(&((*philos + i)->timestamp), NULL) < 0)
			return (-1);
		(*philos + i)->fork_locks[RIGHT] = fork_locks + i;
		(*philos + i)->fork_locks[LEFT] = fork_locks
			+ (i + ctx->num_of_philos - 1) % ctx->num_of_philos;
		i++;
	}
	return (0);
}
