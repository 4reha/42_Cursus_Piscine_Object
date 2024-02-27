NAME = graph

FILES= main.cpp Vector2.cpp Graph.cpp

HEADERS= Vector2.hpp Graph.hpp

FLAGS= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(FILES) $(HEADERS)
	c++ $(FLAGS) $(FILES) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
