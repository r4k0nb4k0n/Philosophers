/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:46:54 by hyechoi           #+#    #+#             */
/*   Updated: 2021/06/30 03:40:47 by hyechoi          ###   ########.fr       */
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

/*
**	Exit if the parameter `target` is NULL, which means NOT malloced normally.
**	Exit with printing error message ERR_MALLOC.
**
**	@param	void	*target	The parameter to check if NULL.
**	@return	void			Nothing.
*/

void	ft_exit_if_null(void *target)
{
	if (!target)
	{
		ft_print_error(ERR_PREFIX, ERR_MALLOC);
		exit(EXIT_FAILURE);
	}
}

/*
**	Exit with system error message.
**
**	@param	char	*prefix	The prefix string.
**	@return	void			Nothing.
*/

void	ft_exit_with_syserr(char *prefix)
{
	perror(prefix);
	exit(EXIT_FAILURE);
}

/*
**	Exit with error message.
**
**	@param	char	*prefix	The prefix string.
**	@param	char	*msg	The error message.
**	@return	void			Nothing.
*/

void	ft_exit_with_error_msg(char *prefix, char *msg)
{
	ft_print_error(prefix, msg);
	exit(EXIT_FAILURE);
}
