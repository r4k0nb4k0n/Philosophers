/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_usage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:37:31 by hyechoi           #+#    #+#             */
/*   Updated: 2021/09/20 19:17:47 by hyechoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Print usage in stderr.
**
**	@param	void	Nothing.
**	@return	int		always return 1.
*/

int	ft_print_usage(void)
{
	ft_print_error(NULL, ERR_USAGE1);
	ft_print_error(NULL, ERR_USAGE2);
	ft_print_error(NULL, ERR_USAGE3);
	return (1);
}
