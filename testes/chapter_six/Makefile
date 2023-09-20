NAME = chapter_six
SRCS = main.c
SRCS += ../../miniRT/sources/tuple_feature/tuple_operation.c
SRCS += ../../miniRT/sources/tuple_feature/searing.c
SRCS += ../../miniRT/sources/tuple_feature/vector_and_point_operation.c
SRCS += ../../miniRT/sources/tuple_feature/tuple_math.c
SRCS += ../../miniRT/sources/tuple_feature/tuples.c
SRCS += ../../miniRT/sources/tuple_feature/putting_it_together.c
SRCS += ../../miniRT/sources/matrices_feature/create_matrices.c
SRCS += ../../miniRT/sources/matrices_feature/determinants.c
SRCS += ../../miniRT/sources/matrices_feature/matrix_operation.c
SRCS += ../../miniRT/sources/rays_feature/create_rays.c
SRCS += ../../miniRT/sources/rays_feature/intersections_transforming.c
SRCS += ../../miniRT/sources/matrices_feature/matrix_transformations.c
SRCS +=	../../miniRT/sources/colors/op_colors.c
SRCS +=	../../miniRT/sources/colors/set_colors.c
SRCS +=	../../miniRT/sources/canvas/canvas.c
SRCS +=	../../miniRT/sources/exit/exit.c 
SRCS += ../../miniRT/sources/rays_feature/light_and_shading.c
CC = cc
FLAGS = -Wall -Wextra -Werror -lm -g ../../miniRT/libft/libft.a ../../minilibx-linux/libmlx.a -lmlx -lX11 -lXext 
OBJS = $(patsubst %.c, %.o, $(wildcard $(SRCS)))
# LIBFT = ../../miniRT/libft/libft.a

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
