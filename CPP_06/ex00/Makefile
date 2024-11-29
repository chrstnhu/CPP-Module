#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 16:00:13 by chrhu             #+#    #+#              #
#    Updated: 2024/11/29 13:13:10 by chrhu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
DEFAULT = \033[0m

# Path
OBJ_DIR = obj

# Srcs
SRCS_PATH = srcs
SRCS = main.cpp Utils.cpp ScalarConverter.cpp Char.cpp Int.cpp Float1.cpp Double.cpp

#Char
# SRCS = Utils.cpp Char.cpp

# Int
# SRCS = Utils.cpp Int.cpp

# Float
# SRCS = Utils.cpp Float.cpp

# Double
# SRCS = Utils.cpp Double.cpp

HEADERS = includes

OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Compile
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow

NAME = convert

$(OBJ_DIR)/%.o: $(SRCS_PATH)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) $(HEADERS)/*.hpp
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re