/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:52:23 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/03 02:37:21 by hyechoi          ###   ########.fr       */
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
