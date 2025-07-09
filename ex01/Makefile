# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 13:42:42 by akyoshid          #+#    #+#              #
#    Updated: 2025/07/09 14:58:46 by akyoshid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		phonebook

INC_DIR =	inc/
SRC_DIR =	src/
OBJ_DIR =	obj/

INC = \
			$(INC_DIR)colors.hpp \
			$(INC_DIR)Contact.hpp \
			$(INC_DIR)PhoneBook.hpp \
			$(INC_DIR)utils.hpp

SRC = \
			$(SRC_DIR)Contact.cpp \
			$(SRC_DIR)main.cpp \
			$(SRC_DIR)PhoneBook.cpp \
			$(SRC_DIR)utils.cpp

OBJ =		$(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRC))

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INC)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

val:
	valgrind --leak-check=full --leak-check=full \
	--show-leak-kinds=definite,indirect,possible \
	--track-fds=yes \
	--suppressions=valgrind.supp ./$(NAME)

.PHONY: all clean fclean re val
