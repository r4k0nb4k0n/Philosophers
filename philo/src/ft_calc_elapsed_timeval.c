/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_elapsed_timeval.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:44:56 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/24 23:49:49 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_calc_elapsed_timeval(t_timeval before, t_timeval after)
{
	return ((after.tv_sec - before.tv_sec) * 1000
		+ (after.tv_usec - before.tv_usec) / 1000);
}
