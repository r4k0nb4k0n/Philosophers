/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:46:54 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/24 17:15:43 by hyechoi          ###   ########.fr       */
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

void	ft_print_usage(void)
{
	ft_print_error(NULL, ERR_USAGE1);
	ft_print_error(NULL, ERR_USAGE2);
	ft_print_error(NULL, ERR_USAGE3);
}
