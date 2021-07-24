/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 03:32:00 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/25 00:19:19 by hyechoi          ###   ########.fr       */
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
**	<string.h>
**	.. void *memset(void *b, int c, size_t len);
**	<pthread.h>
**	.. int pthread_mutex_init(pthread_mutex_t *mutex,
**	.. const pthread_mutexattr_t *attr);
**	.. int pthread_mutex_destroy(pthread_mutex_t *mutex);
**	<sys/time.h>
**	.. int gettimeofday(struct timeval *restrict tp, void *restrict tzp);
*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

/*
**	Define necessary macros about error.
*/

# define ERR_PREFIX "philo"
# define COLON_SPACE ": "
# define ERR_USAGE1 "usage: ./philo number_of_philosophers time_to_die "
# define ERR_USAGE2 "time_to_eat time_to_sleep "
# define ERR_USAGE3 "[number_of_times_each_philosopher_must_eat]\n"
# define ERR_MALLOC "Failed to malloc\n"
# define ERR_FAILED_INIT_CONTEXT_PHILO "Failed to init the context of philo\n"
# define ERR_FAILED_INIT_FORK_LOCKS "Failed to init fork locks\n"
# define ERR_FAILED_SIMULATE "Failed to simulate\n"

/*
**	Define necessary macros about philosopher status.
*/

# define STA_PHILO_THINKING 0
# define STA_PHILO_EATING 1
# define STA_PHILO_SLEEPING 2
# define STA_PHILO_DIED -1
# define MSG_PHILO_THINKING "is thinking\n"
# define MSG_PHILO_TAKEN_FORK "has taken a fork\n"
# define MSG_PHILO_EATING "is eating\n"
# define MSG_PHILO_SLEEPING "is sleeping\n"
# define MSG_PHILO_DIED "died\n"

/*
**	Define necessary macros.
*/

# define TRUE 1
# define FALSE 0
# define LEFT 0
# define RIGHT 1

/*
**	Define necessary typedef and struct
*/

typedef struct timeval t_timeval;

typedef struct s_context
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_each_philo_must_eat;
	t_timeval		timestamp;
	pthread_mutex_t	print_lock;
	int				killswitch;
}	t_context;

typedef struct s_philo
{
	int				num;
	int				status;
	int				num_of_times_each_philo_must_eat;
	t_timeval		timestamp;
	t_context		*ctx;
	pthread_mutex_t	*fork_locks[2];
	pthread_t		thread;
}	t_philo;

/*
**	ft_character.c
*/

int		ft_isdigit(char c);
int		ft_issign(char c);
int		ft_isspace(char c);

/*
**	ft_string.c
*/

int		ft_strlen(char *s);
int		ft_strncmp(char *s1, char *s2, size_t len);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strdup(char *str);
int		ft_atoi(const char *nptr);

/*
**	ft_putchar_fd.c
*/

void	ft_putchar_fd(char c, int fd);

/*
**	ft_putnbr_fd.c
*/

void	ft_putnbr_fd(int n, int fd);

/*
**	ft_putstr_fd.c
*/

void	ft_putstr_fd(char *s, int fd);

/*
**	ft_error.c
*/

void	ft_print_error(char *prefix, char *msg);
void	ft_print_usage(void);

/*
**	ft_msleep.c
*/

int		ft_msleep(useconds_t milliseconds);

/*
**	ft_check_if_str_int_format.c
*/

int		ft_check_if_str_int_format(char *str);
int		ft_check_if_strs_int_format(int strc, char **strv);

/*
**	ft_init_context_philo.c
*/

int		ft_init_context_philo(t_context *ctx, int paramc, char **paramv);

/*
**	ft_init_fork_locks.c
*/

int		ft_init_fork_locks(pthread_mutex_t **fork_locks, int num_of_forks);

/*
**	ft_clean_fork_locks.c
*/

int		ft_clean_fork_locks(pthread_mutex_t **fork_locks, int num_of_forks);

/*
**	ft_init_philos.c
*/

int		ft_init_philos(t_philo **philos, t_context *ctx,
		pthread_mutex_t *fork_locks);

/*
**	ft_calc_elapsed_timeval.c
*/

long	ft_calc_elapsed_timeval(t_timeval before, t_timeval after);

/*
**	ft_print_philosopher_status.c
*/

int		ft_print_philosopher_status(t_philo *philo, char *msg);

/*
**	ft_philo_think.c
*/

int		ft_philo_think(t_philo *p);

/*
**	ft_philo_eat.c
*/

int		ft_philo_eat(t_philo *p);

/*
**	ft_philo_sleep.c
*/

int		ft_philo_sleep(t_philo *p);

/*
**	ft_run_philo_life.c
*/

void	*ft_run_philo_life(void *philo);

/*
**	ft_watch_philos.c
*/

void	*ft_watch_philos(void *philos);

/*
**	ft_simulate_dining_philosophers.c
*/

int		ft_simulate_dining_philosophers(t_context *ctx, t_philo *philos);

/*
**	ft_clean_dining_philosphers.c
*/

void	ft_clean_dining_philosophers(t_context *ctx,
		pthread_mutex_t **fork_locks, t_philo **philos);

#endif
