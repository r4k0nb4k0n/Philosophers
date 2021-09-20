# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/30 03:29:59 by hyechoi           #+#    #+#              #
#    Updated: 2021/09/20 19:14:28 by hyechoi          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = ./src
SRC_FILE = ft_isdigit.c ft_issign.c ft_isspace.c\
			ft_print_error.c ft_print_usage.c\
			ft_atoi.c ft_strdup.c ft_strlcpy.c\
			ft_strlen.c ft_strncmp.c\
			ft_get_timestamp_ms.c\
			ft_check_args.c ft_check_if_str_int_format.c\
			ft_msleep.c\
			ft_check_philo_status_for_ms.c\
			ft_init_context.c ft_init_fork_locks.c ft_init_philos.c\
			ft_clean_fork_locks.c\
			ft_trylock.c ft_unlock.c\
			ft_print_philo_status.c ft_print_alert.c\
			ft_philo_is_starving.c ft_philo_handle_starve.c ft_philo_is_dead.c\
            ft_philo_take_forks.c ft_philo_drop_forks.c\
			ft_philo_think.c ft_philo_eat.c ft_philo_sleep.c\
			ft_philo_is_done_must_eat.c\
			ft_watch_philos.c\
			ft_run_philo_life.c ft_simulate_dining_philosophers.c\
			ft_clean_dining_philosophers.c\
			philo.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILE))
OBJ_DIR = ./obj
OBJ_FILE = $(SRC_FILE:.c=.o)
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ_FILE))
INC_DIR = ./includes
INC_FILE = philo.h
INCS = $(addprefix $(INC_DIR)/, $(INC_FILE))
INC = -I$(INC_DIR)

all: welcome $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@echo "\n\033[1;37;44m___Generate $@.___\033[0m\n"
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJ_DIR):
	@echo "\n\033[1;37;42m___Generate $@.___\033[0m\n"
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean: welcome
	@echo "\n\033[1;37;41m___Clean object files.___\033[0m\n"
	rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\n\033[1;37;41m___Clean all generated files.___\033[0m\n"
	rm -rf $(NAME)

re: fclean all

welcome:
	@echo "\n\033[1;37;45m# *********************** #\033[0m"
	@echo "\033[1;37;45m# Philosophers by hyechoi #\033[0m"
	@echo "\033[1;37;45m# *********************** #\033[0m\n"

.PHONY: all clean fclean re welcome
