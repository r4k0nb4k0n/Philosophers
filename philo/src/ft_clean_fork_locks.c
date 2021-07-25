/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_fork_locks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:47:28 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/25 19:44:53 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_clean_fork_locks(t_lock **fork_locks, int num_of_forks)
{
	int	i;

	i = 0;
	while (i < num_of_forks)
	{
		if (pthread_mutex_destroy((*fork_locks + i)->mutex) != 0)
			return (-1);
		free((*fork_locks + i)->mutex);
		(*fork_locks + i)->mutex = NULL;
		i++;
	}
	free(*fork_locks);
	*fork_locks = NULL;
	if (i != num_of_forks)
		return (-1);
	return (0);
}
