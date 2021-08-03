/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulate_dining_philosophers.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 16:33:12 by hyechoi           #+#    #+#             */
/*   Updated: 2021/08/03 14:27:55 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_threads_of_philos_param(t_context *ctx, t_philo *philos,
	int	start, int gap)
{
	int	i;

	i = start;
	while (i < ctx->num_of_philos)
	{
		ft_msleep(10);
		if (pthread_create(&(philos[i].thread), NULL, &ft_run_philo_life,
				(void *)(philos + i)) != 0)
			return (-1);
		i += gap;
	}
	return (0);
}

/*
**	Create threads of philos.
**
**	@param	t_context	*ctx
**	@param	t_philo		*philos
**	@return int			res			Return 0 if success
**									Return -1 if failure
*/

int	ft_create_threads_of_philos(t_context *ctx, t_philo *philos)
{
	if (ctx->num_of_philos % 2 == 0)
	{
		if (ft_create_threads_of_philos_param(ctx, philos, 0, 2) < 0)
			return (-1);
		if (ft_create_threads_of_philos_param(ctx, philos, 1, 2) < 0)
			return (-1);
	}
	else
	{
		if (ft_create_threads_of_philos_param(ctx, philos, 1, 2) < 0)
			return (-1);
		if (ft_create_threads_of_philos_param(ctx, philos, 0, 2) < 0)
			return (-1);
	}
	return (0);
}

/*
**	Join threads of philos.
**
**	@param	t_context	*ctx
**	@param	t_philo		*philos
**	@return int			res			Return 0 if success
**									Return -1 if failure
*/

int	ft_join_threads_of_philos(t_context *ctx, t_philo *philos)
{
	int	i;
	int	res;
	int	ret;

	i = 0;
	ret = 0;
	while (i < ctx->num_of_philos)
	{
		if (pthread_join(philos[i].thread, (void **)&res) != 0)
		{
			if (res < 0)
				ret = res;
		}
		i++;
	}
	return (ret);
}

/*
**	Simulate dining philosophers problem.
**
**	@param	t_context	*ctx
**	@param	t_philo		*philos
**	@return	int			res			Return 0 if success
**									Return -1 if failure
*/

int	ft_simulate_dining_philosophers(t_context *ctx, t_philo *philos)
{
	int			res_philos;
	int			res_watcher;
	pthread_t	watcher;

	if (pthread_create(&watcher, NULL, &ft_watch_philos, (void *)philos) != 0)
		return (-1);
	if (ft_create_threads_of_philos(ctx, philos) < 0)
		return (-1);
	res_philos = ft_join_threads_of_philos(ctx, philos);
	if (res_philos < 0)
		return (res_philos);
	if (pthread_join(watcher, (void **)&res_watcher) != 0)
		return (res_watcher);
	return (0);
}
