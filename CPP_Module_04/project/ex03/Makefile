# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 22:01:03 by dpentlan          #+#    #+#              #
#    Updated: 2024/02/19 18:53:36 by dpentlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = interface_recap

### SETTINGS ###
CXX := c++
SRC_DIR := 
OBJ_DIR := 
H_DIR := .
FLAGS := -g -std=c++98 -Wall -Wextra -Werror -MMD

### PRETTY COLORS ###
RED:=\033[31;1;4m
GREEN:=\033[32;1;4m
BLUE:=\033[34;1;4m
NOCOLOR:=\033[0m

### FILES ###

SRCS = main.cpp \
			 AMateria.cpp \
			 Ice.cpp \
			 Cure.cpp \
			 Character.cpp \
			 MateriaSource.cpp \

OBJS := $(patsubst %.cpp,$(OBJ_DIR)%.o,$(SRCS))
DEPS := $(patsubst %.cpp,$(OBJ_DIR)%.d,$(SRCS))

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
	rm -f $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

clear:
	@clear

andrun: clear re
	@./$(NAME)

valgrind: clear re
	@valgrind ./$(NAME)

-include $(DEPS)

.PHONY: all clean fclean re andrun

