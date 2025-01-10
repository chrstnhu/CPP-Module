# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 11:00:35 by chrhu             #+#    #+#              #
#    Updated: 2025/01/10 11:56:10 by chrhu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
DEFAULT = \033[0m

#SRCS
SRCS = main.cpp
HEADERS = easyfind.hpp easyfind.tpp
OBJS = $(SRCS:.cpp=.o)

# Compiler and flags
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -Wshadow

NAME = easyfind

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) has been created!$(DEFAULT)"

clean :
	rm -f $(OBJS)
	@echo "$(YELLOW)Object files have been removed!$(DEFAULT)"

fclean : clean
	rm -f $(NAME)
	@echo "$(YELLOW)$(NAME) has been removed!$(DEFAULT)"

re : fclean all

.PHONY : all clean fclean re
