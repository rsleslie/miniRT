NAME = chapter_five
SRCS = main.c
SRCS += ../../miniRT/sources/tuple_feature/tuple_operation.c
SRCS += ../../miniRT/sources/tuple_feature/searing.c
SRCS += ../../miniRT/sources/tuple_feature/vector_and_point_operation.c
SRCS += ../../miniRT/sources/tuple_feature/tuple_math.c
SRCS += ../../miniRT/sources/tuple_feature/tuples.c
SRCS += ../../miniRT/sources/tuple_feature/putting_it_together.c
SRCS += ../../miniRT/sources/matrices_feature/create_matrices.c
SRCS += ../../miniRT/sources/matrices_feature/determinants.c
SRCS += ../../miniRT/sources/matrices_feature/calculate_rotate.c
SRCS += ../../miniRT/sources/matrices_feature/matrix_operation.c
SRCS += ../../miniRT/sources/rays_feature/create_rays.c
SRCS += ../../miniRT/sources/rays_feature/intersect_ray.c
SRCS += ../../miniRT/sources/rays_feature/intersections_transforming.c
SRCS += ../../miniRT/sources/rays_feature/light_and_shading.c
SRCS += ../../miniRT/sources/matrices_feature/matrix_transformations.c
SRCS +=	../../miniRT/sources/colors/op_colors.c
SRCS +=	../../miniRT/sources/colors/set_colors.c
SRCS +=	../../miniRT/sources/canvas/canvas.c
SRCS +=	../../miniRT/sources/exit/exit.c 
SRCS += ../../miniRT/sources/parser/args_validation.c
SRCS += ../../miniRT/sources/parser/aux_validation.c
SRCS += ../../miniRT/sources/parser/obj_validation.c
SRCS += ../../miniRT/sources/parser/parser.c
SRCS += ../../miniRT/sources/parser/read_file.c
SRCS += ../../miniRT/sources/parser/value_validation.c
SRCS += ../../miniRT/sources/parser/check_file.c
SRCS += ../../miniRT/sources/parser/color_validation.c
SRCS += ../../miniRT/sources/parser/camera_validation.c
SRCS += ../../miniRT/sources/parser/ambient_validation.c
SRCS += ../../miniRT/sources/parser/sphere_validation.c
SRCS += ../../miniRT/sources/parser/plane_validation.c
SRCS += ../../miniRT/sources/parser/cylinder_validation.c
SRCS += ../../miniRT/sources/parser/create_object.c
SRCS += ../../miniRT/sources/parser/creating_obj.c
SRCS += ../../miniRT/sources/parser/creating_ambient.c
SRCS += ../../miniRT/sources/parser/add_obj.c
SRCS += ../../miniRT/sources/world_feature/building_world.c
SRCS += ../../miniRT/sources/world_feature/defining_a_view.c
SRCS += ../../miniRT/sources/world_feature/shadowed.c
SRCS += ../../miniRT/sources/world_feature/normal_at.c
SRCS += ../../miniRT/sources/world_feature/camera.c
SRCS += ../../miniRT/sources/world_feature/normal_at_cy.c
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
