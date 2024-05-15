# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 13:41:25 by flverge           #+#    #+#              #
#    Updated: 2024/05/15 13:53:05 by flverge          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = account

# Compiler
CC = c++

# Compiler flags
FLAGS = -Wall -Wextra -Werror -std=c++98 -g

# Source files
SRC := $(wildcard *.cpp)
OBJ := ${SRC:.cpp=.o}

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
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(BOLD)$(RED)🛠️            Compiling $(NAME)...      🛠️$(RESET)"
	@echo "\n"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(BOLD)$(GREEN)🚀    $(NAME) fully compiled, ready to use     🚀$(RESET)"

clean:
	@rm -f $(OBJ)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned .o $(NAME)'s files   🌀$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned $(NAME) executable   🌀$(RESET)"

re: fclean all

.PHONY: all clean fclean re