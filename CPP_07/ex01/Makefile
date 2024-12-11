# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 11:42:06 by chrhu             #+#    #+#              #
#    Updated: 2024/12/11 13:03:55 by chrhu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
DEFAULT = \033[0m

# SRCS
SRCS = main.cpp
HEADER = iter.hpp
OBJS = $(SRCS:%.cpp=%.o)

# Compiler 
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow

NAME = iter

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Executable '$(NAME)' has been created successfully!$(DEFAULT)" 

clean :
	@rm -f $(OBJS)
	@echo "$(GREEN)Cleaned up $(OBJS) $(DEFAULT)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(GREEN)Removed executable '$(NAME)' $(DEFAULT)"

re : fclean all

.PHONY : all clean fclean re
