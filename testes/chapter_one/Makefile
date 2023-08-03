NAME = teste
SRCS = main.c \
	../../miniRT/sources/tuples/operationVectorPoint.c \
	../../miniRT/sources/tuples/tuples.c \
	../../miniRT/sources/tuples/tuple_math.c \
	../../miniRT/sources/tuples/operation_tuple.c \
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
