/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:23:05 by hyechoi           #+#    #+#             */
/*   Updated: 2021/09/13 19:28:23 by hyechoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Return if the character is digit.
**
**	@param	char	c	The character.
**	@return	int		res	Whether the character is digit or not.
*/

int	ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}
