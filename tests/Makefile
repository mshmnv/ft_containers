.PHONY: all clean fclean re test

NAME		= containers

CC			= clang++

FLAGS		= -Wall -Wextra -Werror -std=c++98

INC			= ../vector.hpp ../list.hpp ../stack.hpp ../queue.hpp ../map.hpp ../Node.hpp ../RBTnode.hpp

SRC			= test_vector.cpp test_list.cpp test_stack.cpp test_queue.cpp test_map.cpp

OBJ_DIR		= ./objects/

OBJ			= $(patsubst %.cpp,$(OBJ_DIR)%.o,$(SRC))


all: $(NAME) $(INC)

$(OBJ_DIR)%.o:%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(INC) $(OBJ) main.cpp
	$(CC) $(FLAGS) main.cpp $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: all
	./containers