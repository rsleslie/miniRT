NAME = teste
SRCS = main.c ../../miniRT/sources/matrices/create_matrices.c ../../miniRT/sources/operationsTuples/tuples.c
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

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
