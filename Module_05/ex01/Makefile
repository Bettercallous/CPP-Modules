
NAME = Form

SRC = main.cpp Bureaucrat.cpp Form.cpp

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