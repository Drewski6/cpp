# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 22:01:03 by dpentlan          #+#    #+#              #
#    Updated: 2024/03/28 19:35:13 by dpentlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = span

### SETTINGS ###
CXX := c++
SRC_DIR := 
OBJ_DIR := 
H_DIR := .
FLAGS := -g -std=c++98 -Wall -Wextra -Werror

### PRETTY COLORS ###
RED:=\033[31;1;4m
GREEN:=\033[32;1;4m
BLUE:=\033[34;1;4m
NOCOLOR:=\033[0m

### FILES ###

SRCS = main.cpp \
			 Span.cpp \

OBJS := $(patsubst %.cpp,$(OBJ_DIR)%.o,$(SRCS))

### RULES ###

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $@
	@printf "$(GREEN)|=:=:=:=:=:=:=:=:= DONE =:=:=:=:=:=:=:=:=|$(NOCOLOR)\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@printf "$(BLUE)|=:=:=:=:=:=:=:= BUILDING =:=:=:=:=:=:=:=|$(NOCOLOR)\n"
	@mkdir -p $(dir $@)
	$(CXX) $(FLAGS) -c $(addprefix -I,$(H_DIR)) $< -o $@

clean:
	@printf "$(RED)|=:=:=:=:=:=:=:= CLEANING =:=:=:=:=:=:=:=|$(NOCOLOR)\n"
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

clear:
	@clear

andrun: clear re
	@./$(NAME)

valgrind: clear re
	@valgrind ./$(NAME)

.PHONY: all clean fclean re andrun

