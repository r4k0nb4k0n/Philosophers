/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 03:36:39 by hyechoi           #+#    #+#             */
/*   Updated: 2021/08/25 14:54:38 by hyechoi          ###   ########.fr       */
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

/*
**	Init array of fork locks.
**
**	@param	t_lock	**fork_locks
**	@param	int		num_of_forks
**	@return	res		Return 0 if success.
**					Return -1 if failure.
*/

int	ft_init_fork_locks(t_lock **fork_locks, int num_of_forks)
{
	int	i;

	*fork_locks = malloc(sizeof(t_lock) * num_of_forks);
	if (*fork_locks == NULL)
		return (-1);
	i = 0;
	while (i < num_of_forks)
	{
		(*fork_locks + i)->mutex = malloc(sizeof(pthread_mutex_t));
		if ((*fork_locks + i)->mutex == NULL)
			break ;
		if (pthread_mutex_init((*fork_locks + i)->mutex, NULL) != 0)
			break ;
		i++;
	}
	if (i != num_of_forks)
	{
		ft_clean_fork_locks(fork_locks, i);
		return (-1);
	}
	return (0);
}

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

/*
**	Init philos with context and fork locks.
**	And then simulate dining philosophers.
**
**	@param	t_context	*ctx
**	@param	t_lock		**f_locks
**	@param	t_philo		**ps
**	@return	int			res
*/

int	ft_prep_and_work(t_context *ctx, t_lock **f_locks, t_philo **ps)
{
	int	res;

	res = ft_init_philos(ps, ctx, *f_locks);
	if (res >= 0)
		res = ft_simulate_dining_philosophers(ctx, *ps);
	if (ft_msleep(1000) < 0)
		return (-1);
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
	t_context	ctx;
	t_lock		*fork_locks;
	t_philo		*philos;

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
