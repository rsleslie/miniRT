/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:28:53 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 17:08:11 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include "colors.h"
# include "minirt.h"

t_color		get_color(double r, double g, double b);
t_color		add_colors(t_color c1, t_color c2);
t_color		sub_colors(t_color c1, t_color c2);
t_color		hadamard_product(t_color c1, t_color c2);
t_color		color_scale(double f, t_color color);
int			set_color(t_color color);
t_color		rgb_to_double(t_color color);
void		init_canvas(t_data *data);
void		img_pix_put(t_data *data, int x, int y, int color);
int			terminate(t_data *data);
int			render(t_data *data);
int			handle_keypress(int keysym, t_data *data);
t_canvas	create_canvas(t_canvas canvas, int x, int y, t_color color);
int			render_canvas(t_data *data);

#endif
