# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 01:38:44 by oubelhaj          #+#    #+#              #
#    Updated: 2023/11/15 17:19:00 by oubelhaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRC = main.cpp PhoneBook.cpp Contacts.cpp Helpers.cpp

OBJ = ${SRC:.cpp=.o}

CXX = c++

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all