/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 03:36:39 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/03 02:40:21 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	The main function of the program named `philo`.
**	philosopher with threads and mutex.
**	Receive below as the arguments.
**	.. number_of_philosophers
**	.. time_to_die
**	.. time_to_eat
**	.. time_to_sleep
**	.. [number_of_times_each_philosopher_must_eat]
**
**	@param	int		argc	Argument count.
**	@param	char	**argv	Argument vector.
**	@return	int		status	Return EXIT_FAILURE if error occurs.
**							Return EXIT_SUCCESS if success.
*/

int	main(int argc, char **argv)
{
	if (5 <= argc && argc <= 6
		&& ft_check_if_strs_int_format(argc - 1, argv + 1))
		printf("Go philo!\n");
	else
	{
		ft_print_error(NULL, ERR_USAGE1);
		ft_print_error(NULL, ERR_USAGE2);
		ft_exit_with_error_msg(NULL, ERR_USAGE3);
	}
	return (EXIT_SUCCESS);
}
