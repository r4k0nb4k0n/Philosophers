/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 03:36:39 by hyechoi           #+#    #+#             */
/*   Updated: 2021/09/13 21:09:31 by hyechoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	The main function of the program named `philo`.
**	philosopher with threads and mutexes.
**	1. Receive below as the arguments.
**	.. number_of_philosophers
**	.. time_to_die
**	.. time_to_eat
**	.. time_to_sleep
**	.. [number_of_times_each_philosopher_must_eat]
**	2. Validate arguments.
**	3. Init context.
**	4. Init fork locks.
**	5. Init philos.
**	6. Simulate dining philosophers.
**	7. Clean dining philosophers.
**
**	@param	int		argc	Argument count.
**	@param	char	**argv	Argument vector.
**	@return	int		status	Return 1 if error occurs.
**							Return 0 if success.
*/

int	main(int ac, char **av)
{
	t_context	ctx;
	t_lock		*fork_locks;
	t_philo		*philos;
	int			res;

	res = (ac < 5 || ac > 6 || !ft_check_if_strs_int_format(ac - 1, av + 1));
	if (res == TRUE)
		ft_print_usage();
	else
		res = ft_init_context(&ctx, ac - 1, av + 1);
	if (res < 0)
		ft_print_error(ERR_PREFIX, ERR_FAILED_INIT_CONTEXT);
	else
		res = ft_init_fork_locks(&fork_locks, ctx.num_of_philos);
	if (res < 0)
		ft_print_error(ERR_PREFIX, ERR_FAILED_INIT_FORK_LOCKS);
	else
		res = ft_init_philos(&philos, &ctx, fork_locks);
	if (res == 0)
		res = ft_simulate_dining_philosophers(&ctx, philos);
	if (res < 0)
		ft_print_error(ERR_PREFIX, ERR_FAILED_SIMULATE);
	ft_clean_dining_philosophers(&ctx, &fork_locks, &philos);
	return (res < 0);
}
