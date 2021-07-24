/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_fork_locks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:47:28 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/24 17:41:49 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_clean_fork_locks(pthread_mutex_t **fork_locks, int num_of_forks)
{
	int	i;

	i = 0;
	while (i < num_of_forks && pthread_mutex_destroy(*fork_locks + i) == 0)
		i++;
	free(*fork_locks);
	*fork_locks = NULL;
	if (i != num_of_forks)
		return (-1);
	return (0);
}
