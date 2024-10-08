# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 16:40:13 by chrhu             #+#    #+#              #
#    Updated: 2024/10/08 14:16:51 by chrhu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
DEFAULT = \033[0m

# PATH
OBJ_DIR = obj

# SOURCES
SRCS = main.cpp 
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# COMPILE
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = brain

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Executable '$(NAME)' has been created successfully!$(DEFAULT)" 

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

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
