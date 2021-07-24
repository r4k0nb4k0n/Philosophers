/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 03:36:39 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/24 17:41:17 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_prep_and_work(t_context *ctx, pthread_mutex_t **f_locks, t_philo **ps)
{
	int	res;

	res = ft_init_philos(ps, ctx, *f_locks);
	if (res >= 0)
		res = ft_simulate_dining_philosophers(ctx, *ps);
	ft_clean_dining_philosophers(ctx, f_locks, ps);
	return (res);
}

/*
**	The main function of the program named `philo`.
**	philosopher with threads and mutex.
**	Receive below as the arguments.
**	.. number_of_philosophers
**	.. time_to_die
**	.. time_to_eat
**	.. time_to_sleep
**	.. [number_of_times_each_philosopher_must_eat]
**
**	@param	int		argc	Argument count.
**	@param	char	**argv	Argument vector.
**	@return	int		status	Return EXIT_FAILURE if error occurs.
**							Return EXIT_SUCCESS if success.
*/

int	main(int ac, char **av)
{
	t_context		ctx;
	pthread_mutex_t	*fork_locks;
	t_philo			*philos;

	if (ac < 5 || ac > 6 || !ft_check_if_strs_int_format(ac - 1, av + 1))
	{
		ft_print_usage();
		return (EXIT_FAILURE);
	}
	if (ft_init_context_philo(&ctx, ac - 1, av + 1) < 0)
	{
		ft_print_error(ERR_PREFIX, ERR_FAILED_INIT_CONTEXT_PHILO);
		return (EXIT_FAILURE);
	}
	if (ft_init_fork_locks(&fork_locks, ctx.num_of_philos) < 0)
	{
		ft_print_error(ERR_PREFIX, ERR_FAILED_INIT_FORK_LOCKS);
		return (EXIT_FAILURE);
	}
	if (ft_prep_and_work(&ctx, &fork_locks, &philos) < 0)
	{
		ft_print_error(ERR_PREFIX, ERR_FAILED_SIMULATE);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
