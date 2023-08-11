NAME = teste
SRCS = main.c
SRCS += ../../miniRT/sources/tuple_operation/tuple_operation.c
SRCS += ../../miniRT/sources/tuple_operation/vector_and_point_operation.c
SRCS += ../../miniRT/sources/tuple_operation/tuple_math.c
SRCS += ../../miniRT/sources/tuple_operation/tuples.c
SRCS += ../../miniRT/sources/matrices/create_matrices.c
SRCS += ../../miniRT/sources/matrices/determinants.c
SRCS += ../../miniRT/sources/matrices/matrix_operation.c
CC = cc
FLAGS = -Wall -Wextra -Werror -lm -g
OBJS = $(patsubst %.c, %.o, $(wildcard $(SRCS)))
LIBFT = ../../miniRT/libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ../../miniRT/libft
	$(CC) $(OBJS) $(LIBFT) $(FLAGS) -o $(NAME)

run: all
	valgrind --leak-check=full --tool=memcheck --show-leak-kinds=all --track-origins=yes ./$(NAME)

clean:
	rm -rf $(OBJS)
	@make fclean -C ../../miniRT/libft

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
