# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 15:32:00 by rleslie-          #+#    #+#              #
#    Updated: 2023/08/11 15:49:31 by rleslie-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
SRCS += ./miniRT/sources/tuple_operation/tuple_operation.c
SRCS += ./miniRT/sources/tuple_operation/vector_and_point_operation.c
SRCS += ./miniRT/sources/tuple_operation/tuple_math.c
SRCS += ./miniRT/sources/tuple_operation/tuples.c
SRCS += ./miniRT/sources/tuple_operation/putting_it_together.c
SRCS += ./miniRT/sources/matrices/create_matrices.c
SRCS += ./miniRT/sources/matrices/determinants.c
SRCS += ./miniRT/sources/matrices/matrix_operation.c