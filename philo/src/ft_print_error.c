/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:37:02 by hyechoi           #+#    #+#             */
/*   Updated: 2021/09/13 19:37:06 by hyechoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Print error message in stderr.
**
**	@param	char	*prefix	The prefix string.
**	@param	char	*msg	The error message.
**	@return	void			Nothing.
*/

void	ft_print_error(char *prefix, char *msg)
{
	if (prefix)
	{
		write(STDERR_FILENO, prefix, ft_strlen(prefix));
		write(STDERR_FILENO, COLON_SPACE, ft_strlen(COLON_SPACE));
	}
	if (msg)
		write(STDERR_FILENO, msg, ft_strlen(msg));
}
