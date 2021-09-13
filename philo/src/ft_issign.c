/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:26:27 by hyechoi           #+#    #+#             */
/*   Updated: 2021/09/13 19:28:33 by hyechoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Return if the character is sign.
**
**	@param	char	c	The character.
**	@return	int		res	Whether the character is sign or not.
*/

int	ft_issign(char c)
{
	return (c == '+' || c == '-');
}
