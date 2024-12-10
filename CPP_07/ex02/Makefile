# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 11:42:06 by chrhu             #+#    #+#              #
#    Updated: 2024/12/10 16:46:44 by chrhu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SRCS
SRCS = main.cpp
HEADER = Array.hpp
OBJS = $(SRCS:%.cpp=%.o)

# Compiler 
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow

NAME = array

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
