
NAME = zombie

SRC = main.cpp newZombie.cpp Zombie.cpp randomChump.cpp

OBJ = ${SRC:.cpp=.o}

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all