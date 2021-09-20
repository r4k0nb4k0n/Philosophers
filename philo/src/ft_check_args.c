/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:10:56 by hyechoi           #+#    #+#             */
/*   Updated: 2021/09/20 19:14:48 by hyechoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Check if arguments are valid.
**
**	@param	int		argc
**	@param	char	**argv
**	@return	int		res		Return 0 if all valid.
**							Return -1 if not
*/

int	ft_check_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6
		|| !ft_check_if_strs_int_format(argc - 1, argv + 1))
		return (-1);
	return (0);
}
