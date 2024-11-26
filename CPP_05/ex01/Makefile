# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 15:09:59 by chrhu             #+#    #+#              #
#    Updated: 2024/11/26 14:14:06 by chrhu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
DEFAULT = \033[0m

# Path
OBJ_DIR = obj

# Source
SRCS_PATH = srcs
SRCS = main.cpp Utils.cpp Bureaucrat.cpp Form.cpp
HEADERS = includes

OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Compile
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow

NAME = Bureaucrat

$(OBJ_DIR)/%.o: $(SRCS_PATH)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) $(HEADERS)/*.hpp
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "$(GREEN)Executable '$(NAME)' has been created successfully!$(DEFAULT)" 

clean : 
		@echo "$(YELLOW)rm -rf $(OBJS)$(DEFAULT)"
		@rm -rf $(OBJ_DIR)
		@rm -f $(OBJS)
		@echo "$(GREEN)Cleaned up $(OBJS)!$(DEFAULT)"

fclean : clean
		@echo "$(YELLOW)rm -f $(NAME)"
		@rm -f $(NAME)
		@echo "$(GREEN)Removed executable '$(NAME)'!$(DEFAULT)"

re : fclean all

.PHONY: all clean fclean re
