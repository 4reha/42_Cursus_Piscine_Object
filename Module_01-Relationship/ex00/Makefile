NAME = working

FILES= main.cpp Worker.cpp

HEADERS= Position.hpp Statistic.hpp Shovel.hpp Hammer.hpp Worker.hpp Tool.hpp Workshop.hpp

FLAGS= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(FILES) $(HEADERS)
	c++ $(FLAGS) $(FILES) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
