# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 15:32:00 by rleslie-          #+#    #+#              #
#    Updated: 2023/08/11 17:43:29 by rleslie-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
SRCS += ./miniRT/sources/tuple_feature/tuple_operation.c
SRCS += ./miniRT/sources/tuple_feature/vector_and_point_operation.c
SRCS += ./miniRT/sources/tuple_feature/tuple_math.c
SRCS += ./miniRT/sources/tuple_feature/tuples.c
SRCS += ./miniRT/sources/tuple_feature/putting_it_together.c
SRCS += ./miniRT/sources/matrices_feature/create_matrices.c
SRCS += ./miniRT/sources/matrices_feature/determinants.c
SRCS += ./miniRT/sources/matrices_feature/matrix_operation.c