# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 19:22:57 by chrhu             #+#    #+#              #
#    Updated: 2024/10/15 16:50:20 by chrhu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
DEFAULT = \033[0m

# PATH
OBJ_DIR = obj

# SOURCES
OPERATOR_SRC = operators/increment_decrement.cpp operators/arithmetic.cpp \
				operators/comparison.cpp operators/min_max.cpp

SRCS = main.cpp Fixed.cpp Point.cpp $(OPERATOR_SRC)

HEADERS = includes/Fixed.hpp includes/Point.hpp
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# COMPILE
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = fixed

$(OBJ_DIR)/%.o: %.cpp  $(HEADERS)
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/operators
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Executable '$(NAME)' has been created successfully!$(DEFAULT)" 

clean: 
	@echo "$(YELLOW)rm -rf $(OBJS)$(DEFAULT)"
	@rm -rf $(OBJ_DIR)
	@rm -f $(OBJS)
	@echo "$(GREEN)Cleaned up $(OBJS)!$(DEFAULT)"

fclean: clean
	@echo "$(YELLOW)rm -f $(NAME)"
	@rm -f $(NAME)
	@echo "$(GREEN)Removed executable '$(NAME)'!$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re
