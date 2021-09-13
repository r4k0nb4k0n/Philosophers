/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:29:17 by hyechoi           #+#    #+#             */
/*   Updated: 2021/09/13 19:30:01 by hyechoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Compare two strings with given length.
**
**	@param	char	*s1
**	@param	char	*s2
**	@param	size_t		len
**	@return	int			res
*/

int	ft_strncmp(char *s1, char *s2, size_t len)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;
	int				ret;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	ret = 0;
	while (i < len)
	{
		ret = *(p1 + i) - *(p2 + i);
		if (ret != 0)
			break ;
		if (*(p1 + i) == '\0' || *(p2 + i) == '\0')
			break ;
		i++;
	}
	return (ret);
}
