/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:03:50 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/07 20:26:44 by rleslie-         ###   ########.fr       */
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
int		validation_str(char **str);
int		validation_range_float(float n, float st, float end);
int		validation_range_float(float num, float start, float end);
int		validation_range_int(int num, int start, int end);
int		validation_float(char *str);
int		validation_int(char *str);
int		validation_color(char *str);

#endif