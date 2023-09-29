# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 15:32:00 by rleslie-          #+#    #+#              #
#    Updated: 2023/09/29 16:04:48 by rleslie-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

SRCS += ./sources/minirt.c
SRCS += ./sources/canvas/canvas.c
SRCS += ./sources/canvas/exit.c
SRCS += ./sources/tuple_feature/tuple_operation.c
SRCS += ./sources/tuple_feature/vector_and_point_operation.c
SRCS += ./sources/tuple_feature/tuple_math.c
SRCS += ./sources/tuple_feature/tuples.c
SRCS += ./sources/matrices_feature/calculate_rotate.c
SRCS += ./sources/matrices_feature/create_matrices.c
SRCS += ./sources/matrices_feature/determinants.c
SRCS += ./sources/matrices_feature/matrix_operation.c
SRCS += ./sources/matrices_feature/matrix_transformations.c
SRCS += ./sources/matrices_feature/searing.c
SRCS += ./sources/colors/op_colors.c
SRCS += ./sources/colors/set_colors.c
SRCS += ./sources/parser/add_obj.c
SRCS += ./sources/parser/ambient_validation.c
SRCS += ./sources/parser/args_validation.c 
SRCS += ./sources/parser/aux_validation.c 
SRCS += ./sources/parser/camera_validation.c 
SRCS += ./sources/parser/check_file.c 
SRCS += ./sources/parser/color_validation.c 
SRCS += ./sources/parser/create_object.c 
SRCS += ./sources/parser/creating_ambient.c 
SRCS += ./sources/parser/creating_obj.c 
SRCS += ./sources/parser/cylinder_validation.c 
SRCS += ./sources/parser/obj_validation.c 
SRCS += ./sources/parser/parser.c 
SRCS += ./sources/parser/plane_validation.c 
SRCS += ./sources/parser/read_file.c 
SRCS += ./sources/parser/sphere_validation.c 
SRCS += ./sources/parser/value_validation.c 
SRCS += ./sources/rays_feature/create_rays.c
SRCS += ./sources/rays_feature/intersect_ray.c
SRCS += ./sources/rays_feature/intersections_transforming.c 
SRCS += ./sources/rays_feature/light_and_shading.c 
SRCS += ./sources/world_feature/building_world.c 
SRCS += ./sources/world_feature/camera.c
SRCS += ./sources/world_feature/world_free.c
SRCS += ./sources/world_feature/defining_a_view.c 
SRCS += ./sources/world_feature/normal_at_cy.c 
SRCS += ./sources/world_feature/normal_at.c 
SRCS += ./sources/world_feature/shadowed.c
SRCS += ./sources/render/events.c
SRCS += ./sources/render/init_mlx.c
SRCS += ./sources/render/init_render.c

INC = $(addprefix ./includes/, 	canvas.h \
								colors.h \
								matrices.h \
								miniRT.h \
								object.h \
								parser.h \
								rays.h \
								render.h \
								struct.h \
								tuple.h \
								world.h)

CC = cc
FLAGS = -Wall -Wextra -Werror -g3
LINKERS = -lm -lmlx -lX11 -lXext
LIB = libft/libft.a
RM = rm -rf
INCLUDES = ./includes
OBJS = $(patsubst %.c, %.o, $(wildcard $(SRCS)))

%.o:%.c $(INC)
	$(CC) $(FLAGS) -I./minilibx-linux/ -I./libft -c $< -o $@
	printf "$(GREEN).$(RC)"

all: $(NAME)

$(NAME): $(INC) $(OBJS)
	@make -C libft
	@$(CC) $(FLAGS) $(OBJS) $(LIB) ../minilibx-linux/libmlx.a $(LINKERS) -o $(NAME)

run: all
	valgrind --leak-check=full --tool=memcheck --show-leak-kinds=all --track-origins=yes ./$(NAME) 

clean:
	@$(RM) $(OBJS)
	@make fclean -C libft

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

