/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_dining_philosophers.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:21:31 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/24 17:24:22 by hyechoi          ###   ########.fr       */
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

void	ft_clean_dining_philosophers(t_context *ctx,
		pthread_mutex_t **fork_locks, t_philo **philos)
{
	free(*philos);
	*philos = NULL;
	ft_clean_fork_locks(fork_locks, ctx->num_of_philos);
	pthread_mutex_destroy(&(ctx->print_lock));
}
