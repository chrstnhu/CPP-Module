# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 11:51:00 by chrhu             #+#    #+#              #
#    Updated: 2025/01/10 11:56:15 by chrhu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
DEFAULT = \033[0m

# SRCS
SRCS = main.cpp Span.cpp
HEADERS = Span.hpp
OBJS = $(SRCS:.cpp=.o)

# Compiler and flags
CC = c++
CFLAGS = -Walll -Wextra -Werror --std=c++98 -Wshadow

NAME = span

all : $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME) : $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) has been created!$(DEFAULT)"

clean : rm -f $(OBJS)
	@echo "$(YELLOW)Object files have been removed!$(DEFAULT)"

fclean : rm -f $(NAME)
	@echo "$(YELLOW)$(NAME) has been removed!$(DEFAULT)"

re : fclean all

.PHONY : all clean fclean re