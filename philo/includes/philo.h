/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 03:32:00 by hyechoi           #+#    #+#             */
/*   Updated: 2021/06/30 03:54:42 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Get include-guarded.
*/

#ifndef PHILO_H
# define PHILO_H

/*
**	Include header files in need.
**	<stdio.h>
**	.. int printf(cosnt char * restrict format, ...);
**	<stdlib.h>
**	.. void *malloc(size_t size);
**	.. void free(void *ptr);
**	<unistd.h>
**	.. ssize_t write(int filedes, const void *buf, size_t nbyte);
*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
**	Define necessary macros about error.
*/

# define ERR_PREFIX "philo"
# define COLON_SPACE ": "
# define ERR_USAGE "usage: ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n"
# define ERR_MALLOC "failed to malloc\n"

/*
**	Define necessary macros.
*/

/*
**	ft_string.c
*/

int		ft_strlen(char *s);
int		ft_strncmp(char *s1, char *s2, size_t len);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);

/*
**	ft_error.c
*/

void	ft_print_error(char *prefix, char *msg);
void	ft_exit_if_null(void *target);
void	ft_exit_with_syserr(char *prefix);
void	ft_exit_with_error_msg(char *prefix, char *msg);

#endif
