NAME = teste
SRCS = main.c \
	../../miniRT/sources/operationsTuples/operationVectorPoint.c \
	../../miniRT/sources/operationsTuples/tuples.c \
	../../miniRT/sources/operationsTuples/tuple_math.c \
	../../miniRT/sources/operationsTuples/operation_tuple.c \
CC = cc
FLAGS = -Wall -Wextra -Werror -lm
OBJS = $(patsubst %.c, %.o, $(wildcard $(SRCS)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(FLAGS) -o $(NAME)

run: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
