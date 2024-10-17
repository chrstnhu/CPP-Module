# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 18:14:51 by chrhu             #+#    #+#              #
#    Updated: 2024/10/17 18:27:21 by chrhu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
DEFAULT = \033[0m

# Source
SRCS = main.cpp ClapTrap.cpp 
HEADERS = ClapTrap

OBJS = $(SRCS:%.cpp=$(SRCS)/%.o)

# Compile
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ClapTrack

all : $(NAME)

$(NAME) : $(HEADER)
		$(CC) $(CFLAGS) -o $(NAME)

clean : rm -f $(OBJS)

fclean : clean
		rm -f $(NAME);

re : fclean all

.phony ALL MAKE CLEAN FCLEAN