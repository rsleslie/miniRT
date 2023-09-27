/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:08:28 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/27 17:04:23 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

t_world	        world(void);
t_xs	        order_xs(t_xs xs);
t_intersection	intersection_world(double n, t_sphere s);
t_comps	        prepare_computations(t_intersection i, t_rays r);
t_color	        shade_hit(t_world *w, t_comps comps);
t_color	        color_at(t_world *w, t_rays r);
t_matrices	    view_transform(t_tuple from, t_tuple to, t_tuple up);
t_c_world	    camera(double hsize, double vsize, double field_of_view);
t_rays	        ray_for_pixel(t_c_world camera, double px, double py);
void            render_img(t_c_world c, t_world *w);
t_matrices	    view_transform_two(t_tuple from, t_tuple to, t_tuple up);
t_xs	        local_intersect(t_pl pl, t_rays r, t_xs xs);
int             is_shadowed(t_world *w, t_tuple p);
t_intersection	hit(t_world *w, t_rays r);
t_tuple	normal_at_world(t_sp sp, t_tuple p);
t_tuple local_normal_at(t_pl pl, t_tuple local_point);
t_tuple	normal_at_pl(t_pl pl, t_tuple p);

#endif