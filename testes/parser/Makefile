NAME = parser
SRCS = main.c
SRCS += ../../miniRT/sources/tuple_feature/tuple_operation.c
SRCS += ../../miniRT/sources/tuple_feature/vector_and_point_operation.c
SRCS += ../../miniRT/sources/tuple_feature/tuple_math.c
SRCS += ../../miniRT/sources/tuple_feature/tuples.c
SRCS += ../../miniRT/sources/tuple_feature/putting_it_together.c
SRCS += ../../miniRT/sources/matrices_feature/create_matrices.c
SRCS += ../../miniRT/sources/matrices_feature/determinants.c
SRCS += ../../miniRT/sources/matrices_feature/matrix_operation.c
SRCS += ../../miniRT/sources/rays_feature/create_rays.c
SRCS += ../../miniRT/sources/rays_feature/intersections_transforming.c
SRCS += ../../miniRT/sources/parser/args_validation.c
SRCS += ../../miniRT/sources/parser/obj_validation.c
SRCS += ../../miniRT/sources/parser/parser.c
SRCS += ../../miniRT/sources/parser/read_file.c
SRCS += ../../miniRT/sources/parser/value_validation.c
SRCS += ../../miniRT/sources/parser/check_file.c
CC = cc
FLAGS = -Wall -Wextra -Werror -lm -g
OBJS = $(patsubst %.c, %.o, $(wildcard $(SRCS)))
LIBFT = ../../miniRT/libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ../../miniRT/libft
	$(CC) $(OBJS) $(LIBFT) $(FLAGS) -o $(NAME)

run: all
	valgrind --track-fds=yes --leak-check=full --tool=memcheck --show-leak-kinds=all --track-origins=yes ./$(NAME)

clean:
	rm -rf $(OBJS)
	@make fclean -C ../../miniRT/libft

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

