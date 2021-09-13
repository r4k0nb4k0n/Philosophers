/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_usage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:37:31 by hyechoi           #+#    #+#             */
/*   Updated: 2021/09/13 19:38:26 by hyechoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Print usage in stderr.
**
**	@param	void	Nothing.
**	@return	void	Nothing.
*/

void	ft_print_usage(void)
{
	ft_print_error(NULL, ERR_USAGE1);
	ft_print_error(NULL, ERR_USAGE2);
	ft_print_error(NULL, ERR_USAGE3);
}
