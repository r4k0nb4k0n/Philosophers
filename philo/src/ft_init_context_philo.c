/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_context_philo.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:21:10 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/29 20:08:36 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Initialize the context of philo with given parameters.
**
**	@param	t_context	*ctx		The context of philo.
**	@param	int			paramc		Parameter count.
**	@param	char		**paramv	Parameter vector.
**	@return	int			res			Return 0 if valid.
**									Return -1 if invalid.
*/

int	ft_init_context_philo(t_context *ctx, int paramc, char **paramv)
{
	memset(ctx, 0, sizeof(t_context));
	ctx->num_of_philos = ft_atoi(paramv[0]);
	ctx->time_to_die = ft_atoi(paramv[1]);
	ctx->time_to_eat = ft_atoi(paramv[2]);
	ctx->time_to_sleep = ft_atoi(paramv[3]);
	if (paramc == 5)
		ctx->num_of_times_each_philo_must_eat = ft_atoi(paramv[4]);
	if (ctx->num_of_philos < 1 || ctx->time_to_die < 0
		|| ctx->time_to_eat < 0 || ctx->time_to_sleep < 0
		|| (paramc == 5 && ctx->num_of_times_each_philo_must_eat < 1))
		return (-1);
	(ctx->print_lock).mutex = malloc(sizeof(pthread_mutex_t));
	if ((ctx->print_lock).mutex == NULL)
		return (-1);
	if (pthread_mutex_init((ctx->print_lock).mutex, NULL) != 0)
		return (-1);
	ctx->timestamp = ft_get_timestamp_ms();
	if (ctx->timestamp < 0)
		return (-1);
	return (0);
}
