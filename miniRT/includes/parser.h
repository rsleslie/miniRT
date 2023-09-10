/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:03:50 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/10 18:49:45 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "miniRT.h"

int		    check_file(char **argv);
int		    check_arg(int argc);
char	    **read_file(char *file);
int		    validation_ambient(char **str);
int		    validation_args(char **str);
int		    validation_acl(char **str);
int		    validation_obj(char **str);
int		    validation_of_file_arguments(char **str);
int		    validation_range_float(float n, float st, float end);
int		    validation_range_float(float num, float start, float end);
int		    validation_range_int(int num, int start, int end);
int		    validation_float(char *str);
int		    validation_int(char *str);
int		    validation_color(char *str);
int		    validation_camera(char **str);
int		    validation_normalize_vector(char *str);
int		    validation_coordinates(char *str);
int		    validation_multiples_sphere(char **str);
int		    validation_multiples_plane(char **str);
int		    validation_multiples_cylinder(char **str);
int		    validation_ligth(char **str);
int      	*parser(t_objects **rt, char *file);
void		create_object(t_objects **rt, char **args);
t_c			create_camera(char **args);
t_l			create_ligth(char **args);
t_a			create_ambient(char **a);
void		create_sp(t_objects **rt, char **args);
void		create_plane(t_objects **rt, char **args);
void		create_cy(t_objects **rt, char **args);
int			counter_obj(char *obj, char **args);
void		calloc_obj(char **args, t_objects **rt);
t_color		color_obj(char *str);
t_tuple		get_coordenates(char *args);
t_tuple		get_vector(char *args);
t_sp		add_sp(char **str);
t_pl		add_pl(char **str);
t_cy		add_cy(char **str);

#endif