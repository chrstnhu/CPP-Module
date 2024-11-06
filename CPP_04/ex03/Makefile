# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 17:09:31 by chrhu             #+#    #+#              #
#    Updated: 2024/11/06 13:41:32 by chrhu            ###   ########.fr        #
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
SRCS = AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp

HEADERS = includes

OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Compile
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Materia

$(OBJ_DIR)/%.o: $(SRCS_PATH)/%.cpp $(HEADERS)/*.hpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) 
		$(CC) $(CFLAGS) main.cpp $(OBJS) -o $(NAME)
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