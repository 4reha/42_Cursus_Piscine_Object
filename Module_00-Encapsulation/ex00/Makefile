NAME = cih_bank

FILES= main.cpp Bank.cpp 

HEADERS= Bank.hpp 

FLAGS= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(FILES) $(HEADERS)
	c++ $(FLAGS) $(FILES) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
