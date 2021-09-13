/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:30:10 by hyechoi           #+#    #+#             */
/*   Updated: 2021/09/13 19:30:19 by hyechoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	strlcpy
**
**	@param	char		*dst
**	@param	char	*src
**	@param	size_t		dstsize
**	@return	size_t		len
*/

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	char	*dp;
	char	*sp;

	if (src == NULL)
		return (0);
	sp = src;
	if (dst != NULL)
	{
		dp = dst;
		while (*sp && dstsize > 1)
		{
			*dp++ = *sp++;
			dstsize--;
		}
		if (dstsize >= 1)
			*dp = '\0';
	}
	while (*sp)
		sp++;
	return (sp - src);
}
