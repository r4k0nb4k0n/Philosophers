/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:26:50 by hyechoi           #+#    #+#             */
/*   Updated: 2021/09/13 19:28:38 by hyechoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Return if the character is space.
**
**	@param	char	c	The character.
**	@return	int		res	Whether the character is space or not.
*/

int	ft_isspace(char c)
{
	return (('\t' <= c && c <= '\r') || c == ' ');
}
