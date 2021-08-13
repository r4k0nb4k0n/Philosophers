/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:24:50 by hyechoi           #+#    #+#             */
/*   Updated: 2021/08/13 14:07:07 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Print alert message.
**
**	@param	t_philo	*philo
**	@param	char	*msg
**	@return	int		res		Return 0 if success
**							Return -1 if failure
*/

int	ft_print_alert(t_lock *print_lock, char *msg)
{
	while (TRUE)
	{
		if (ft_trylock(print_lock) >= 0)
			break ;
	}
	printf("%s", msg);
	if (ft_unlock(print_lock) < 0)
		return (-1);
	return (0);
}
