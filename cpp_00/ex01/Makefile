# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 13:04:54 by flverge           #+#    #+#              #
#    Updated: 2024/05/14 12:27:12 by flverge          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = phonebook

# Compiler
CC = c++

# Compiler flags
FLAGS = -Wall -Wextra -Werror -std=c++98 -g

# Source files
SRC_DIR := src
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := ${SRC:.cpp=.o}

# Includes
INC =	-I ./includes/

# Colors
RESET = \033[0m
BOLD = \033[1m
RED = \033[91m
GREEN = \033[92m
YELLOW = \033[33m
ORANGE = \033[93m
BLUE = \033[94m

all: $(NAME)

%.o: %.cpp
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(BOLD)$(RED)🛠️            Compiling $(NAME)...      🛠️$(RESET)"
	@echo "\n"
	@$(CC) $(FLAGS) $(INC) $(OBJ) -o $(NAME)
	@echo "$(BOLD)$(GREEN)🚀    $(NAME) fully compiled, ready to use     🚀$(RESET)"

clean:
	@rm -f $(OBJ)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned .o $(NAME)'s files   🌀$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned $(NAME) executable   🌀$(RESET)"

re: fclean all

.PHONY: all clean fclean re