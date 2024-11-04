# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 18:14:51 by chrhu             #+#    #+#              #
#    Updated: 2024/11/04 18:06:03 by chrhu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
DEFAULT = \033[0m

# Path
OBJ_DIR = obj

# Source
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
HEADERS = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Compile
CC = c++

# Compiler flag : (activate)-W-shadow and (desactivate)-Wno-shadow
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow
NAME = ClapTrap

$(OBJ_DIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
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