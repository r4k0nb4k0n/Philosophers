/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:06:05 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/03 02:37:52 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Return the length of string.
**
**	@param	char	*s	The string.
**	@return	int		c	The length of the string.
*/

int	ft_strlen(char *s)
{
	char	*p;

	p = s;
	while (*p)
		p++;
	return (p - s);
}

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

/*
**	Duplicate a string.
**
**	@param	 char	*str	A string to duplicate.
**	@return	char		*ret	A duplicated string.
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

/*
**	Tranform number string to int value.
**
**	@param	const char	*nptr	The target number string to transform.
**	@return	int			ret		The tranformed int value.
*/

int	ft_atoi(const char *nptr)
{
	int	ret;
	int	sign;

	ret = 0;
	sign = 1;
	while (*nptr && ft_isspace(*nptr))
		nptr++;
	if (*nptr && ft_issign(*nptr))
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr && ft_isdigit(*nptr))
	{
		ret = ret * 10;
		ret += (*nptr - '0') * sign;
		if (ret > 0 && sign < 0)
			return (0);
		else if (ret < 0 && sign > 0)
			return (-1);
		nptr++;
	}
	return (ret);
}
