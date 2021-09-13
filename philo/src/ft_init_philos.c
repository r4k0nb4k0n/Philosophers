/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:25:10 by hyechoi           #+#    #+#             */
/*   Updated: 2021/09/13 20:08:05 by hyechoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Init array of philos.
**
**	@param	t_philo		**philos
**	@param	t_context	*ctx
**	@param	t_lock		*fork_locks
**	@return	int			res
*/

int	ft_init_philos(t_philo **philos, t_context *ctx, t_lock *fork_locks)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * ctx->num_of_philos);
	if (*philos == NULL)
		return (-1);
	memset(*philos, 0, sizeof(t_philo) * ctx->num_of_philos);
	i = 0;
	while (i < ctx->num_of_philos)
	{
		(*philos + i)->num = i + 1;
		(*philos + i)->ctx = ctx;
		(*philos + i)->num_of_times_each_philo_must_eat
			= ctx->num_of_times_each_philo_must_eat;
		(*philos + i)->timestamp = ft_get_timestamp_ms();
		((*philos + i)->vital_lock).mutex = malloc(sizeof(pthread_mutex_t));
		if (((*philos + i)->vital_lock).mutex == NULL)
			break ;
		if (pthread_mutex_init(((*philos + i)->vital_lock).mutex, NULL) != 0)
			break ;
		(*philos + i)->fork_locks[LEFT] = fork_locks + i;
		(*philos + i)->fork_locks[RIGHT] = fork_locks
			+ (i + ctx->num_of_philos - 1) % ctx->num_of_philos;
		i++;
	}
	return (0);
}
