/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_dining_philosophers.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:21:31 by hyechoi           #+#    #+#             */
/*   Updated: 2021/09/14 10:40:59 by hyechoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Clean all dining philosophers.
**
**	@param	t_context		*ctx
**	@param	pthread_mutex_t	**fork_locks;
**	@param	t_philo			**philos;
**	@return void							Nothing.
*/

void	ft_clean_dining_philosophers(t_context *ctx, t_lock **fork_locks,
		t_philo **philos)
{
	int	i;

	i = 0;
	while (i < ctx->num_of_philos)
	{
		pthread_mutex_destroy(((*philos + i)->eat_lock).mutex);
		free(((*philos + i)->eat_lock).mutex);
		((*philos + i)->eat_lock).mutex = NULL;
		i++;
	}
	free(*philos);
	*philos = NULL;
	ft_clean_fork_locks(fork_locks, ctx->num_of_philos);
	pthread_mutex_destroy((ctx->print_lock).mutex);
	free((ctx->print_lock).mutex);
	(ctx->print_lock).mutex = NULL;
}
