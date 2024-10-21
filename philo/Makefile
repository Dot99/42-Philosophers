# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 09:43:10 by gude-jes          #+#    #+#              #
#    Updated: 2024/07/18 14:21:08 by gude-jes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                     NAMES                                    #
#==============================================================================#

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -g
NAME		= philo

INC			= -I./includes
RM			= rm -rf

GENERAL		= main handler loop start
UTILS		= valid_args forks dead philo_val
INIT		= init_forks init_philo init_args
#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

VPATH 		= src\
			src/utils\
			src/init\

SRC			= $(addsuffix .c, $(GENERAL))\
			$(addsuffix .c, $(UTILS))\
			$(addsuffix .c, $(INIT))\

OBJ_DIR		= obj
OBJS		= $(SRC:%.c=$(OBJ_DIR)/%.o)

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -pthread -o $(NAME)

$(OBJ_DIR):
	@mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o

clean:
	@$(RM) $(OBJS) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME) $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re

.SILENT:
