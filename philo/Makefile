# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/30 03:29:59 by hyechoi           #+#    #+#              #
#    Updated: 2021/06/30 04:41:02 by hyechoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = ./src
SRC_FILE = ft_character.c ft_string.c ft_check_if_str_int_format.c ft_error.c\
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
	@echo "\n$$(tput setaf 7; tput setab 2; tput bold)___Generate $@.___$$(tput sgr 0)\n"
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJ_DIR):
	@echo "\n$$(tput setaf 7; tput setab 4; tput bold)___Generate $@.___$$(tput sgr 0)\n"
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean: welcome
	@echo "\n$$(tput setaf 7; tput setab 1; tput bold)___Clean object files.___$$(tput sgr 0)\n"
	rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\n$$(tput setaf 7; tput setab 1; tput bold)___Clean all generated files.___$$(tput sgr 0)\n"
	rm -rf $(NAME)

re: fclean all

welcome:
	@echo "\n$$(tput setaf 7; tput setab 5; tput bold)# **************** #$$(tput sgr 0)"
	@echo "$$(tput setaf 7; tput setab 5; tput bold)# philo by hyechoi #$$(tput sgr 0)"
	@echo "$$(tput setaf 7; tput setab 5; tput bold)# **************** #$$(tput sgr 0)\n"

.PHONY: all clean fclean re welcome
