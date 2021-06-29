/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_str_int_format.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 04:19:10 by hyechoi           #+#    #+#             */
/*   Updated: 2021/06/30 04:39:45 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Check if string is in valid integer format.
**
**	@param	char	*str
**	@return	int		res		Return TRUE if valid
**							Return FALSE if not
*/

int	ft_check_if_str_int_format(char *str)
{
	char	*p;

	p = str;
	while (*p && ft_isspace(*p))
		p++;
	if (ft_issign(*p))
		p++;
	while (*p)
	{
		if (!ft_isdigit(*p))
			return (FALSE);
		p++;
	}
	return (TRUE);
}

/*
**	Check if strings are valid integer.
**	1. 
**
**	@param	int		strc
**	@param	char	**strv
**	@return	int		res		Return TRUE if all valid
**							Return FALSE if not
*/

int	ft_check_if_strs_int_format(int strc, char **strv)
{
	int	i;

	i = 0;
	while (i < strc)
	{
		if (!ft_check_if_str_int_format(strv[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
