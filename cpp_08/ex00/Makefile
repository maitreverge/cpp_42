# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 09:35:55 by flverge           #+#    #+#              #
#    Updated: 2024/07/25 13:33:01 by ubuntu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = easy_find

# Colors
RESET = \033[0m
BOLD = \033[1m
RED = \033[91m
GREEN = \033[92m
YELLOW = \033[33m
ORANGE = \033[93m

# Compiler
CC = c++

# Compiler flags
FLAGS = -Wall -Wextra -Werror -Wshadow -Wno-reorder -std=c++98

# Source files
SRC_DIR := src
SRC := $(wildcard $(SRC_DIR)/*.cpp)

# Objects files
OBJ_DIR := obj
OBJ := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

# Includes
INC = -I includes/

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(BOLD)$(RED)🛠️            Compiling $(NAME)...      🛠️$(RESET)"
	@echo "\n"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(BOLD)$(GREEN)🚀    $(NAME) fully compiled, ready to use     🚀$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned .o $(NAME)'s files   🌀$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned $(NAME) executable   🌀$(RESET)"

re: fclean all

.PHONY: all clean fclean re