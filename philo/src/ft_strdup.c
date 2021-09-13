/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:30:43 by hyechoi           #+#    #+#             */
/*   Updated: 2021/09/13 19:31:09 by hyechoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Duplicate a string.
**
**	@param	char	*str	A string to duplicate.
**	@return	char	*ret	A duplicated string.
*/

char	*ft_strdup(char *str)
{
	char	*ret;
	size_t	len_str;

	len_str = ft_strlen((char *)str);
	ret = malloc(len_str + 1);
	if (ret != NULL)
		ft_strlcpy(ret, str, len_str + 1);
	return (ret);
}
