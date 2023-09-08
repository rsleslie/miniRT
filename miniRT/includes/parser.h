/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:03:50 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/08 18:24:00 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "miniRT.h"

int		check_file(char **argv);
int		check_arg(int argc);
char	**read_file(char *file);
int		parser(char *file);
int		validation_ambient(char **str);
int		validation_args(char **str);
int		validation_acl(char **str);
int		validation_obj(char **str);
int		validation_of_file_arguments(char **str);
int		validation_range_float(float n, float st, float end);
int		validation_range_float(float num, float start, float end);
int		validation_range_int(int num, int start, int end);
int		validation_float(char *str);
int		validation_int(char *str);
int		validation_color(char *str);
int	    validation_camera(char **str);
int	    validation_normalize_vector(char *str);
int	    validation_coordinates(char *str);
int	    validation_multiples_sphere(char **str);
int	    validation_multiples_plane(char **str);
int	    validation_multiples_cylinder(char **str);

#endif