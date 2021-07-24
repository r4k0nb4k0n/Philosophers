/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fork_locks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:10:30 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/22 21:00:24 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Init array of fork locks.
**
**	@param	pthread_mutex_t	**fork_locks
**	@param	int				num_of_forks
**	@return	res				Return 0 if success.
**							Return -1 if failure.
*/

int	ft_init_fork_locks(pthread_mutex_t **fork_locks, int num_of_forks)
{
	int	i;

	*fork_locks = malloc(sizeof(pthread_mutex_t) * num_of_forks);
	if (*fork_locks == NULL)
		return (-1);
	i = 0;
	while (i < num_of_forks)
	{
		if (pthread_mutex_init(*fork_locks + i, NULL) != 0)
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
