# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 14:14:06 by chrhu             #+#    #+#              #
#    Updated: 2024/09/24 15:48:18 by chrhu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
DEFAULT = \033[0m

# SOURCES
SRCS = main.cpp Harl.cpp
HEADERS = Harl.hpp
OBJS = $(SRCS:%.cpp=%.o)

# COMPILE
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = HarlFilter

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Executable '$(NAME)' has been created successfully!$(DEFAULT)" 

clean: 
	@echo "$(YELLOW)rm -rf $(OBJS)$(DEFAULT)" 
	@rm -f $(OBJS)
	@echo "$(GREEN)Cleaned up $(OBJS)!$(DEFAULT)"

fclean: clean
	@echo "$(YELLOW)rm -f $(NAME)"
	@rm -f $(NAME)
	@echo "$(GREEN)Removed executable '$(NAME)'!$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re
