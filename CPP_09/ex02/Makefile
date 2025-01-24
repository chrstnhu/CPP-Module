# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 12:24:36 by chrhu             #+#    #+#              #
#    Updated: 2025/01/24 17:19:31 by chrhu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
DEFAULT = \033[0m

# Path
OBJ_DIR = obj

#SRCS
SRCS_PATH = srcs
# SRCS = main_deque.cpp SortDeque.cpp PmergeMe.cpp
# SRCS = main.cpp
SRCS = main_vector.cpp SortVector.cpp PmergeMe.cpp

HEADERS = includes

OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

#Compile
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow

NAME = PmergeMe

$(OBJ_DIR)/%.o : $(SRCS_PATH)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) $(HEADERS)/*.hpp
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) has been created!$(DEFAULT)"

clean :
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Object files have been removed!$(DEFAULT)"

fclean : clean
	rm -f $(NAME)
	@echo "$(YELLOW)$(NAME) has been removed!$(DEFAULT)"

re : fclean all

.PHONY : all clean fclean re

